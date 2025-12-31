#include <stdio.h>
#include "shell/shell.h"
#include "download/source.h"

int main(int argc, const char* argv[])
{
    const char* name = downloadSource("v0.1.0-alpha.5");
    printf("%s\n", name);

    return 0;
}
