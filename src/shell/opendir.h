#pragma once

#include "shell_.h"

CommandResult openDir(const char* path, CommandResult (*fn)(void*), void* ctx);
