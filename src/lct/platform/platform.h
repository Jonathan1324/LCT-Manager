#pragma once

#ifdef __cplusplus
extern "C" {
#endif

static inline const char* getExtension()
{
#ifdef _WIN32
    return ".zip";
#else
    return ".tar.gz";
#endif
}

#ifdef __cplusplus
}
#endif