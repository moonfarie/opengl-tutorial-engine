#pragma once

#include <filesystem>
#include <string>

namespace utilities {

std::string read_file_as_str(const std::filesystem::path& path);

}  // namespace utilities
