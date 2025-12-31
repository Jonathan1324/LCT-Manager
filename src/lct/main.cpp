#include <iostream>
#include "download/download.hpp"
#include "platform/platform.h"

int main(int argc, const char* argv[])
{
    const char* version = "v0.1.0-alpha.5";

    std::string source_url = getSourceURL(version);
    std::filesystem::path source_archive = std::string("lct-") + version + getExtension();

    int res = download(source_url, source_archive);
    if(res != 0) {
        std::cerr << "Download failed with code: " << res << std::endl;
    } else {
        std::cout << "Download succeeded!" << std::endl;
    }
    
    return 0;
}
