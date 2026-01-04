#pragma once

#include <filesystem>
#include <vector>

void install_version(const char* version_str, const std::filesystem::path& source_dir, const std::filesystem::path& dest_dir, const std::vector<std::string>& tools);
void uninstall_version(const std::filesystem::path& dest_dir, const std::vector<std::string>& tools);
