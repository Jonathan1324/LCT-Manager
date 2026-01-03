#pragma once

#include <filesystem>

void install_version(const char* version_str, const std::filesystem::path& source_dir, const std::filesystem::path& dest_dir);
void uninstall_version(const std::filesystem::path& dest_dir);
