#ifndef DATABASE_BUFFER_H
#define DATABASE_BUFFER_H

#include <stddef.h>

typedef struct
{
    char *buffer;
    size_t buffer_size;
    size_t content_size;
} database_buffer;

database_buffer *buffer_new(size_t size);
database_buffer *buffer_realloc(database_buffer *buffer, size_t size);

#endif // !DATABASE_BUFFER_H
