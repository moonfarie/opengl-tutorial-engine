#pragma once

#include <GLFW/glfw3.h>

namespace platform {

class GLFW {
 public:
  GLFW();
  ~GLFW();

  void swap_buffers(GLFWwindow* window) const;
  void poll_events() const;
};

}  // namespace platform
