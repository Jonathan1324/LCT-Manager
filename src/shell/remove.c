#include "remove.h"
#include "shell_.h"

int sh_remove(const char* path)
{
#ifdef _WIN32
    const char* base1 = "Remove-Item -Recurse -Force ";
    const char* base2 = "";
#else
    const char* base1 = "rm -rf -- \"";
    const char* base2 = "\"";
#endif
    return shell2Bases(base1, base2, path);
}
