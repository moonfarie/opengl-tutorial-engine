#pragma once

#include "glad/glad.h"

namespace render {

class UniqueVAO {
 public:
  UniqueVAO() { glGenVertexArrays(1, &array_); }
  ~UniqueVAO() {
    if (array_ != 0) {
      glDeleteVertexArrays(1, &array_);
    }
  }

  UniqueVAO(const UniqueVAO&) = delete;
  UniqueVAO& operator=(const UniqueVAO&) = delete;

  void bind() const { glBindVertexArray(array_); }
  void unbind() const { glBindVertexArray(0); }

 private:
  GLuint array_{0};
};

}  // namespace render
