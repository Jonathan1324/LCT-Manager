#include "copy.h"
#include "mkdir.h"
#include "shell_.h"

int copy(const char* path, const char* dest) // TODO: fix windows
{
    sh_mkdir(dest);
#ifdef _WIN32
    const char* base1 = "Copy-Item -Recurse -Force ";
    const char* base2 = " ";
    const char* base3 = "";
#else
    const char* base1 = "cp -R -- \"";
    const char* base2 = "\" \"";
    const char* base3 = "\"";
#endif
    return shell3Bases(base1, base2, base3, path, dest);
}
