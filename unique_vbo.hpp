#pragma once

#include "glad/glad.h"

namespace render {

class UniqueVBO {
 public:
  UniqueVBO() { glGenBuffers(1, &buffer_); }
  ~UniqueVBO() {
    if (buffer_ != 0) {
      glDeleteBuffers(1, &buffer_);
    }
  }

  UniqueVBO(const UniqueVBO&) = delete;
  UniqueVBO& operator=(const UniqueVBO&) = delete;

  void bind() const { glBindBuffer(GL_ARRAY_BUFFER, buffer_); }
  void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

 private:
  GLuint buffer_{0};
};

}  // namespace render
