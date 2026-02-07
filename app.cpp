#include "app.hpp"

App::App()
    : window_{800, 600, "OpenGL Tutorial Engine"}, display_{window_.width(), window_.height()} {
  display_.init_framebuffer_size_callback(window_.handle());
}

void App::run() const {
  while (not window_.should_close()) {
    renderer_.draw_frame();

    glfw_.swap_buffers(window_.handle());
    glfw_.poll_events();
  }
}
