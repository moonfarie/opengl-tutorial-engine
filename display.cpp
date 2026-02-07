#include "display.hpp"

#include <GLFW/glfw3.h>

namespace platform {

Display::Display(int width, int height) {
  glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

void Display::init_framebuffer_size_callback(GLFWwindow* window) const {
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Display::framebuffer_size_callback(GLFWwindow*, int width, int height) {
  glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
}

}  // namespace platform
