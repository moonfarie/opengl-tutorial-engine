#pragma once

#include "display.hpp"
#include "glad.hpp"
#include "glfw.hpp"
#include "renderer.hpp"
#include "shader_program.hpp"
#include "window.hpp"

class App {
 public:
  App();
  ~App() = default;

  void run() const;

 private:
  platform::GLFW glfw_;
  platform::Window window_;
  platform::GLAD glad_;
  platform::Display display_;
  render::Renderer renderer_;
  render::ShaderProgram shader_program_;
};
