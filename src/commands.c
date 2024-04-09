#include <commands.h>
#include <stdio.h>

database_command COMMANDS[] = {{".exit", &database_exit},
                               {"insert", &database_insert},
                               {"select", &database_select},
                               {NULL, NULL}};

_Bool database_exit(database_buffer *_unused) { return 1; }

_Bool database_insert(database_buffer *args) { return 0; }

_Bool database_select(database_buffer *args) { return 0; }
