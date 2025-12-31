#pragma once

#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
int invokeShellCall(const char* cmd);
#else
static inline int invokeShellCall(const char* cmd)
{
    return system(cmd);
}
#endif
