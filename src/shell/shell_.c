#include "shell_.h"

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

    int res = invokeSystemCall(full_cmd);
    free(full_cmd);
    return res;
}
#endif

int shell3Bases(const char* b1, const char* b2, const char* b3, const char* c1, const char* c2)
{
    unsigned int b1_length = strlen(b1);
    unsigned int b2_length = strlen(b2);
    unsigned int b3_length = strlen(b3);
    unsigned int c1_length = strlen(c1);
    unsigned int c2_length = strlen(c2);
    unsigned int length = b1_length + b2_length + b3_length + c1_length + c2_length + 1;

    char* cmd = (char*)malloc(length);
    if (!cmd) return -2;

    char* pos = cmd;

    memcpy(pos, b1, b1_length);
    pos += b1_length;

    memcpy(pos, c1, c1_length);
    pos += c1_length;

    memcpy(pos, b2, b2_length);
    pos += b2_length;

    memcpy(pos, c2, c2_length);
    pos += c2_length;

    memcpy(pos, b3, b3_length);
    pos += b3_length;

    *pos = '\0';

    int res = invokeShellCall(cmd);
    free(cmd);
    return res;
}
