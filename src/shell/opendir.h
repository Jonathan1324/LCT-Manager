#pragma once

int openDir(const char* path, int (*fn)(void*), void* ctx);
