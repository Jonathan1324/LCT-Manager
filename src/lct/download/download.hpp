#pragma once

#include <string>
#include <filesystem>
#include <rust.h>

static inline int download(const std::string& url, const std::filesystem::path& target)
{
    return (int)r_download(url.c_str(), target.string().c_str());
}
