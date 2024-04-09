#ifndef DATABASE_COMMANDS_H
#define DATABASE_COMMANDS_H

#include "buffer.h"
#include <unistd.h>

typedef struct
{
    char *name;
    _Bool (*func)(database_buffer *);
} database_command;

_Bool database_exit(database_buffer *buffer);
_Bool database_insert(database_buffer *buffer);
_Bool database_select(database_buffer *buffer);

extern database_command COMMANDS[];

#endif // !DATABASE_COMMANDS_H
