#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct CommandResult {
    int exit_code;
    char* stdout_str;
    char* stderr_str;
} CommandResult;

extern const CommandResult invalidCommandResult;

CommandResult invokeSystemCall(const char* cmd);

#ifdef _WIN32
CommandResult invokeShellCall(const char* cmd);
#else
static inline CommandResult invokeShellCall(const char* cmd)
{
    return invokeSystemCall(cmd);
}
#endif

CommandResult shell2Bases(const char* b1, const char* b2, const char* c1);
CommandResult shell3Bases(const char* b1, const char* b2, const char* b3, const char* c1, const char* c2);
