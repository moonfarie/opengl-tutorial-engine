#include "app.hpp"

App::App() : window_{800, 600, "OpenGL Tutorial Engine"} {}

void App::run() const {
  while (not window_.should_close()) {
    glfw_.poll_events();

    glfw_.swap_buffers(window_.handle());
  }
}
