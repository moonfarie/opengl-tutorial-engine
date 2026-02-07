#pragma once

#include <string>

struct GLFWwindow;

namespace platform {

class Window {
 public:
  Window(int width, int height, const std::string& title);
  ~Window();

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  GLFWwindow* handle() const;
  bool should_close() const;

  int width() const;
  int height() const;

 private:
  void setGLFWWindowHints() const;
  void createGLFWWindow();

  int width_{0};
  int height_{0};
  const std::string title_{""};
  GLFWwindow* glfw_window_{nullptr};
};

}  // namespace platform
