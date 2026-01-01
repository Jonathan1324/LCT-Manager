#include "opendir.h"

#include <unistd.h>
#include <limits.h>

int openDir(const char* path, int (*fn)(void*), void* ctx)
{
    char oldcwd[PATH_MAX];

    if (!getcwd(oldcwd, sizeof(oldcwd)))
        return -1;

    if (chdir(path) != 0)
        return -1;

    int rc = fn(ctx);

    chdir(oldcwd);
    return rc;
}
