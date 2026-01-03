#include "opendir.h"

#include <unistd.h>
#include <limits.h>

CommandResult openDir(const char* path, CommandResult (*fn)(void*), void* ctx)
{
    char oldcwd[PATH_MAX];

    if (!getcwd(oldcwd, sizeof(oldcwd)))
        return invalidCommandResult;

    if (chdir(path) != 0)
        return invalidCommandResult;

    CommandResult rc = fn(ctx);

    chdir(oldcwd);
    return rc;
}
