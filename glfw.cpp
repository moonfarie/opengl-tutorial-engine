#include "glfw.hpp"

#include <stdexcept>

namespace platform {

GLFW::GLFW() {
  if (glfwInit() == GLFW_FALSE) {
    throw std::runtime_error("Failed to initialize GLFW");
  }
}

GLFW::~GLFW() { glfwTerminate(); }

void GLFW::swap_buffers(GLFWwindow* window) const { glfwSwapBuffers(window); }

void GLFW::poll_events() const { glfwPollEvents(); }

}  // namespace platform
