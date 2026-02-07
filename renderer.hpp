#pragma once

namespace render {

class Renderer {
 public:
  Renderer() = default;
  ~Renderer() = default;

  void draw_frame() const;
};

}  // namespace render
