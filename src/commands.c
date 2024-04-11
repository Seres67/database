#include <commands.h>
#include <stdio.h>

database_command COMMANDS[] = {{".exit", &database_exit, 5},
                               {"insert", &database_insert, 6},
                               {"select", &database_select, 6},
                               {NULL, NULL, 0}};

_Bool database_exit(database_buffer *_unused, size_t len) { return 1; }

_Bool database_insert(database_buffer *buffer, size_t len)
{
    char *args = &buffer->buffer[len + 1];
    printf("%s\n", args);
    char *table = NULL;
    char *content = NULL;
    sscanf(args, "%s %s %s", content, NULL, table);
    printf("%s %s\n", content, table);
    return 0;
}

_Bool database_select(database_buffer *args, size_t len) { return 0; }
