#pragma once

#include "glad.hpp"
#include "glfw.hpp"
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
};
