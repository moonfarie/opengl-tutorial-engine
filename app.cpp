#include "app.hpp"

App::App()
    : window_{800, 600, "OpenGL Tutorial Engine"},
      display_{window_.width(), window_.height()},
      shader_program_{"shaders/shader.vert", "shaders/shader.frag"} {
  display_.init_framebuffer_size_callback(window_.handle());
}

void App::run() const {
  while (not window_.should_close()) {
    shader_program_.use();
    renderer_.draw_frame();

    glfw_.swap_buffers(window_.handle());
    glfw_.poll_events();
  }
}
