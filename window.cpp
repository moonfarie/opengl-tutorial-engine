#include "window.hpp"

#include <GLFW/glfw3.h>

#include <stdexcept>

namespace platform {

Window::Window(int width, int height, const std::string& title)
    : width_{width}, height_{height}, title_{title} {
  setGLFWWindowHints();
  createGLFWWindow();

  glfwMakeContextCurrent(glfw_window_);
}

Window::~Window() {
  if (glfw_window_ != nullptr) {
    glfwDestroyWindow(glfw_window_);
    glfw_window_ = nullptr;
  }
}

GLFWwindow* Window::handle() const { return glfw_window_; }

bool Window::should_close() const { return (glfwWindowShouldClose(glfw_window_) != 0); }

int Window::width() const { return width_; }

int Window::height() const { return height_; }

void Window::setGLFWWindowHints() const {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::createGLFWWindow() {
  glfw_window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
  if (glfw_window_ == nullptr) {
    throw std::runtime_error("Failed to create GLFW window");
  }
}

}  // namespace platform
