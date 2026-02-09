#include "utilities.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace utilities {

std::string read_file_as_str(const std::filesystem::path& path) {
  const std::ifstream file{path};

  if (not file.is_open()) {
    throw std::runtime_error("Failed to open file: " + path.string());
  }

  std::ostringstream osstr;
  osstr << file.rdbuf();

  return osstr.str();
}

}  // namespace utilities
