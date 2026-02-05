#pragma once

#include <GLFW/glfw3.h>

namespace platform {

class GLFW {
 public:
  GLFW();
  ~GLFW();

  void poll_events() const;
  void swap_buffers(GLFWwindow* window) const;
};

}  // namespace platform
