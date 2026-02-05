#include "glad.hpp"

#include "glad/glad.h"

#include <GLFW/glfw3.h>

#include <stdexcept>

namespace platform {

GLAD::GLAD() {
  if (0 == gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    throw std::runtime_error("Failed to initialize GLAD");
  }
}

}  // namespace platform
