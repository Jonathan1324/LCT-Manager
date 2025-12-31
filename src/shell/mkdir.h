#pragma once

#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#endif

static inline int sh_mkdir(const char* path)
{
#ifdef _WIN32
    return _mkdir(path);
#else
    return mkdir(path, 0755);
#endif
}
