#include "version.hpp"
#include "../download/download.hpp"
#include "../platform/platform.h"

#include <exception>

std::string getSourceURL(const char* version)
{
    const char* base_url = "https://github.com/Jonathan1324/LCT/archive/refs/tags/";
    return std::string(base_url) + version + getExtension();
}

std::filesystem::path InstallSourceCode(const char* version)
{
    std::string source_url = getSourceURL(version);
    std::filesystem::path source_archive = std::string("lct-") + version + getExtension();

    int res = download(source_url, source_archive);
    if(res != 0) {
        throw std::runtime_error("Failed to download source code");
    }

    // TODO: unarchive

    return source_archive;
}
