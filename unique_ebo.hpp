#pragma once

#include "glad/glad.h"

namespace render {

class UniqueEBO {
 public:
  UniqueEBO() { glGenBuffers(1, &buffer_); }
  ~UniqueEBO() {
    if (buffer_ != 0) {
      glDeleteBuffers(1, &buffer_);
    }
  }

  UniqueEBO(const UniqueEBO&) = delete;
  UniqueEBO& operator=(const UniqueEBO&) = delete;

  void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_); }
  void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

 private:
  GLuint buffer_{0};
};

}  // namespace render
