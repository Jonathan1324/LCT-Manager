#include "state.hpp"
#include <fstream>

bool State::Save(const std::filesystem::path& path) const
{
    std::filesystem::path tmp = path;
    tmp += ".tmp";

    std::ofstream ofs(tmp, std::ios::trunc);
    if (!ofs.is_open()) return false;

    for (const std::pair<const std::string, std::string>& kv : installed_tools) {
        ofs << "tool=" << kv.first << "," << kv.second << "\n";
        if (!ofs) return false;
    }

    ofs.close();
    if (!ofs) return false;

    std::error_code ec;
    std::filesystem::rename(tmp, path, ec);
    if (ec) {
        std::filesystem::remove(tmp);
        return false;
    }

    return true;
}

bool State::Load(const std::filesystem::path& path) {
    installed_tools.clear();

    std::ifstream ifs(path);
    if (!ifs.is_open()) return true;

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.rfind("tool=", 0) == 0) {
            std::size_t comma = line.find(',', 5);
            if (comma != std::string::npos) {
                std::string name = line.substr(5, comma - 5);
                std::string version = line.substr(comma + 1);
                installed_tools[name] = version;
            }
        }
    }

    return true;
}
