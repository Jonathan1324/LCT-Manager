#include "curl.h"

#include "shell_.h"

int curl(const char* url, const char* destination)
{
#ifdef _WIN32
    const char* base1 = "Invoke-WebRequest -Uri \"";
    const char* base2 = "\" -OutFile \"";
    const char* base3 = "\" -UseBasicParsing";
#else
    const char* base1 = "curl -L -f \"";
    const char* base2 = "\" -o \"";
    const char* base3 = "\"";
#endif
    return shell3Bases(base1, base2, base3, url, destination);
}
