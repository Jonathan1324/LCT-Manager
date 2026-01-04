#include "terminal.h"

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

int supportsANSI()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return false;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return false;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) return false;

    return true;
}
#else
#include <unistd.h>

int supportsANSI()
{
    return isatty(fileno(stdout));
}
#endif

