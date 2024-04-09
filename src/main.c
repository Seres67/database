#include <buffer.h>
#include <commands.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_prompt() { printf("> "); }

void read_input(database_buffer *buffer)
{
    ssize_t bytes_read =
        getline(&(buffer->buffer), &(buffer->buffer_size), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(84);
    }

    // Ignore trailing newline
    buffer->content_size = bytes_read - 1;
    buffer->buffer[bytes_read - 1] = 0;
}

int main(int ac, char **av)
{
    database_buffer *buffer = buffer_new(0);
    while (1) {
        _Bool found = 0;
        display_prompt();
        read_input(buffer);

        for (int i = 0; COMMANDS[i].name; ++i) {
            if (!strncmp(buffer->buffer, COMMANDS[i].name,
                         strlen(COMMANDS[i].name))) {
                found = 1;
                if (COMMANDS[i].func(buffer)) {
                    return 0;
                }
            }
        }
        if (!found)
            printf("unrecognized command.\n");
    }
    return 0;
}
