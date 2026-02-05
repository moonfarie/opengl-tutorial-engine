#pragma once

#include <GLFW/glfw3.h>

#include <string>

namespace platform {

class Window {
 public:
  Window(int width, int height, const std::string& title);
  ~Window();

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  bool should_close() const;
  GLFWwindow* handle() const;

 private:
  void setGLFWWindowHints() const;
  void createGLFWWindow();

  int width_{0};
  int height_{0};
  const std::string title_{""};
  GLFWwindow* glfw_window_{nullptr};
};

}  // namespace platform
