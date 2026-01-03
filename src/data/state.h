#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct State {
    int installed;
    const char* version;
} State;

// State_Save:
//  - returns 0 on success
//  - returns not 0 on I/O error
int State_Save(const char* path, const State* state);

// State_Load:
//  - returns 0 on sucess
//  - returns 0 and sets state to default when state file is missing
//  - returns not 0 on I/O error
int State_Load(const char* path, State* state);

#ifdef __cplusplus
}
#endif
