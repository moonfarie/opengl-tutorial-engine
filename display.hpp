#pragma once

struct GLFWwindow;

namespace platform {

class Display {
 public:
  Display(int width, int height);
  ~Display() = default;

  void init_framebuffer_size_callback(GLFWwindow* window) const;

 private:
  static void framebuffer_size_callback(GLFWwindow*, int width, int height);
};

}  // namespace platform
