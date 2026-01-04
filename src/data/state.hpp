#pragma once

#include <unordered_map>
#include <string>
#include <filesystem>

struct State {
    std::unordered_map<std::string, std::string> installed_tools;

    bool Save(const std::filesystem::path& path) const;
    bool Load(const std::filesystem::path& path);

    inline bool IsInstalled(const std::string& name) const
    {
        return installed_tools.find(name) != installed_tools.end();
    }

    inline void SetTool(const std::string& name, const std::string& version)
    {
        installed_tools[name] = version;
    }

    inline void RemoveTool(const std::string& name)
    {
        installed_tools.erase(name);
    }
};
