#include "archive.h"
#include "shell_.h"

int unzip(const char* path, const char* out)
{
#ifdef _WIN32
    const char* base1 = "Expand-Archive -Force ";
    const char* base2 = " ";
    const char* base3 = "";
#else
    const char* base1 = "unzip -o \"";
    const char* base2 = "\" -d \"";
    const char* base3 = "\"";
#endif
    return shell3Bases(base1, base2, base3, path, out);
}

int tar_gz(const char* path, const char* out)
{
#ifdef _WIN32
    const char* base1 = "tar -xzf \"";
    const char* base2 = "\" -C \"";
    const char* base3 = "\"";
#else
    const char* base1 = "tar -xzf \"";
    const char* base2 = "\" -C \"";
    const char* base3 = "\"";
#endif
    return shell3Bases(base1, base2, base3, path, out);
}
