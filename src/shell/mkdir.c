#include "mkdir.h"
#include "shell_.h"

CommandResult sh_mkdir(const char* path)
{
#ifdef _WIN32
    const char* base1 = "New-Item -ItemType Directory -Force '";
    const char* base2 = "'";
#else
    const char* base1 = "mkdir -p \"";
    const char* base2 = "\"";
#endif
    return shell2Bases(base1, base2, path);
}
