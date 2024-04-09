#include <buffer.h>
#include <stdio.h>
#include <stdlib.h>

database_buffer *buffer_new(size_t size)
{
    database_buffer *buffer = malloc(sizeof(database_buffer));

    buffer->buffer = malloc(sizeof(char) * size);
    buffer->buffer_size = size;
    buffer->content_size =
        size < buffer->content_size ? size : buffer->content_size;
    return buffer;
}

database_buffer *buffer_realloc(database_buffer *buffer, size_t size)
{
    char *tmp = realloc(buffer->buffer, size);
    if (!tmp) {
        fprintf(stderr, "couldn't realloc buffer");
        exit(84);
    }
    buffer->buffer = tmp;
    buffer->buffer_size = size;
    buffer->content_size = 0;
    return buffer;
}
