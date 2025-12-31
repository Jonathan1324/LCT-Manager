#include "shell.h"

#ifdef _WIN32
int invokeShellCall(const char* cmd)
{
    const char cmd_before[] = "powershell -Command \"";
    const char cmd_after[] = "\"";
    unsigned int cmd_length = strlen(cmd);

    unsigned int length = sizeof(cmd_before) - 1 + sizeof(cmd_after) - 1 + cmd_length + 1;; // +1 for '\0'
    for (unsigned int i = 0; i < cmd_length; i++) {
        if (cmd[i] == '\"') length++; // Need to include '\' before the '"'
    }

    char* full_cmd = (char*)malloc(length);
    if (!full_cmd) return (int)0xFFFFFFFE;

    unsigned int pos = 0;
    memcpy(full_cmd + pos, cmd_before, sizeof(cmd_before) - 1);
    pos += sizeof(cmd_before) - 1;

    for (unsigned int i = 0; i < cmd_length; i++) {
        if (cmd[i] == '"') {
            full_cmd[pos++] = '\\';
            full_cmd[pos++] = '"';
        } else {
            full_cmd[pos++] = cmd[i];
        }
    }

    memcpy(full_cmd + pos, cmd_after, sizeof(cmd_after) - 1);
    pos += sizeof(cmd_after) - 1;

    full_cmd[pos] = '\0';

    int res = system(full_cmd);
    free(full_cmd);
    return res;
}
#endif
