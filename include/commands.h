#ifndef DATABASE_COMMANDS_H
#define DATABASE_COMMANDS_H

#include "buffer.h"
#include <unistd.h>

typedef struct
{
    char *name;
    _Bool (*func)(database_buffer *, size_t);
    size_t len;
} database_command;

_Bool database_exit(database_buffer *buffer, size_t len);
_Bool database_insert(database_buffer *buffer, size_t len);
_Bool database_select(database_buffer *buffer, size_t len);

extern database_command COMMANDS[];

#endif // !DATABASE_COMMANDS_H
