#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell/shell.h"
#include "download/source.h"

const char* source_dir = "test/a/";
const char* dist_dir = "test/b/";
const char* dist_in_source = "dist";

const char* current = "current";

const char* bin_suffix = "/bin/";

int buildToolchain(void* null)
{
    (null);
#ifdef _WIN32
    const char* cmd = "python -m ci.ci --no-test";
#else
    const char* cmd = "python3 -m ci.ci --no-test";
#endif
    return system(cmd);
}

typedef unsigned char Command;
#define COMMAND_INSTALL ((Command)1)

int main(int argc, const char* argv[])
{
    const char* version_str = "v0.1.0-alpha.5";
    int use_current = 1;

    Command command = COMMAND_INSTALL;

    switch (command)
    {
        case COMMAND_INSTALL: {
            sh_mkdir(source_dir);
            char* name = downloadSource(version_str, source_dir);
            if (!name) {
                fputs("Couldn't download source", stderr);
                return 1;
            }

            size_t source_dir_len = strlen(source_dir);
            size_t name_len = strlen(name);
            size_t length = source_dir_len + name_len + 1;
            char* full = (char*)malloc(length);

            memcpy(full, source_dir, source_dir_len);
            memcpy(full + source_dir_len, name, name_len);
            full[length - 1] = '\0';

            free(name);

            openDir(full, buildToolchain, NULL);

            size_t dist_dir_len = strlen(dist_dir);
            size_t version_len = strlen(use_current ? current : version_str);
            length = dist_dir_len + version_len + 1;
            char* full_dest = (char*)malloc(length);
            memcpy(full_dest, dist_dir, dist_dir_len);
            memcpy(full_dest + dist_dir_len, use_current ? current : version_str, version_len);
            full_dest[length - 1] = '\0';

            size_t full_len = strlen(full);
            size_t dist_in_source_len = strlen(dist_in_source);
            length = full_len + dist_in_source_len + 4; // '/' and '/.'
            char* full_dist = (char*)malloc(length);
            memcpy(full_dist, full, full_len);
            full_dist[full_len] = '/';
            memcpy(full_dist + full_len + 1, dist_in_source, dist_in_source_len);
            full_dist[length - 3] = '/';
            full_dist[length - 2] = '.';
            full_dist[length - 1] = '\0';

            copy(full_dist, full_dest);

            sh_remove(full);

            free(full);
            free(full_dest);
            free(full_dist);

            break;
        }
        
        default:
            break;
    }

    return 0;
}
