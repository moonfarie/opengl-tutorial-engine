#pragma once

#include <filesystem>

#include "glad/glad.h"

namespace render {

class ShaderProgram {
 public:
  ShaderProgram(const std::filesystem::path& vertex_shader_path,
                const std::filesystem::path& fragment_shader_path);
  ~ShaderProgram();

  void use() const;

 private:
  GLuint program_{0};
};

}  // namespace render
