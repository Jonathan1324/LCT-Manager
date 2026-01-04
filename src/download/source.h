#pragma once

#ifdef __cplusplus
extern "C" {
#endif

char* downloadSource(const char* version, const char* path);
char* unpackSource(const char* file_path, const char* path, const char* version);

#ifdef __cplusplus
}
#endif
