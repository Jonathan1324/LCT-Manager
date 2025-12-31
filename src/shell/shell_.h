#pragma once

#include <stdlib.h>
#include <string.h>

static inline int invokeSystemCall(const char* cmd)
{
    return system(cmd);
}

#ifdef _WIN32
int invokeShellCall(const char* cmd);
#else
static inline int invokeShellCall(const char* cmd)
{
    return invokeSystemCall(cmd);
}
#endif

int shell3Bases(const char* b1, const char* b2, const char* b3, const char* c1, const char* c2);
