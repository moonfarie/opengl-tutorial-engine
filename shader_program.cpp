#include "shader_program.hpp"

#include <stdexcept>
#include <string>

#include "utilities.hpp"

namespace {

class UniqueShader {
 public:
  UniqueShader(GLuint shader) : shader_{shader} {}
  ~UniqueShader() {
    if (shader_ != 0) {
      glDeleteShader(shader_);
    }
  }

  UniqueShader(const UniqueShader&) = delete;
  UniqueShader& operator=(const UniqueShader&) = delete;

  GLuint get() const { return shader_; }

 private:
  GLuint shader_{0};
};

class UniqueProgram {
 public:
  UniqueProgram(GLuint program) : program_{program} {}
  ~UniqueProgram() {
    if (program_ != 0) {
      glDeleteProgram(program_);
    }
  }

  UniqueProgram(const UniqueProgram&) = delete;
  UniqueProgram& operator=(const UniqueProgram&) = delete;

  GLuint get() const { return program_; }
  GLuint release() {
    GLuint program = program_;
    program_ = 0;
    return program;
  }

 private:
  GLuint program_{0};
};

GLuint create_shader(GLenum type, const GLchar* source) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  return shader;
}

GLuint create_program(GLuint vertex_shader, GLuint fragment_shader) {
  GLuint program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  return program;
}

bool should_compile_shader(GLuint shader) {
  GLint result = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

  return (result == GL_TRUE);
}

bool should_link_program(GLuint program) {
  GLint result = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &result);

  return (result == GL_TRUE);
}

std::string get_shader_log(GLuint shader) {
  GLint length = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

  std::string log;
  log.resize(static_cast<size_t>(length - 1));  // strip trailing \0

  glGetShaderInfoLog(shader, static_cast<GLsizei>(length), nullptr,
                     static_cast<GLchar*>(log.data()));

  return log;
}

std::string get_program_log(GLuint program) {
  GLint length = 0;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

  std::string log;
  log.resize(static_cast<size_t>(length - 1));  // strip trailing \0

  glGetProgramInfoLog(program, static_cast<GLsizei>(length), nullptr,
                      static_cast<GLchar*>(log.data()));

  return log;
}

}  // namespace

namespace render {

ShaderProgram::ShaderProgram(const std::filesystem::path& vertex_shader_path,
                             const std::filesystem::path& fragment_shader_path) {
  const std::string vertex_shader_code = utilities::read_file_as_str(vertex_shader_path);
  const std::string fragment_shader_code = utilities::read_file_as_str(fragment_shader_path);

  const UniqueShader vertex_shader{create_shader(GL_VERTEX_SHADER, vertex_shader_code.c_str())};

  if (vertex_shader.get() == 0) {
    throw std::runtime_error("Failed to create vertex shader");
  }

  if (not should_compile_shader(vertex_shader.get())) {
    throw std::runtime_error("Failed to compile vertex shader:\n" +
                             get_shader_log(vertex_shader.get()));
  }

  const UniqueShader fragment_shader{
      create_shader(GL_FRAGMENT_SHADER, fragment_shader_code.c_str())};

  if (fragment_shader.get() == 0) {
    throw std::runtime_error("Failed to create fragment shader");
  }

  if (not should_compile_shader(fragment_shader.get())) {
    throw std::runtime_error("Failed to compile fragment shader:\n" +
                             get_shader_log(fragment_shader.get()));
  }

  UniqueProgram program{create_program(vertex_shader.get(), fragment_shader.get())};

  if (not should_link_program(program.get())) {
    throw std::runtime_error("Failed to link shader program:\n" + get_program_log(program.get()));
  }

  program_ = program.release();

  glDetachShader(program_, vertex_shader.get());
  glDetachShader(program_, fragment_shader.get());
}

ShaderProgram::~ShaderProgram() {
  if (program_ != 0) {
    glDeleteProgram(program_);
  }
}

void ShaderProgram::use() const { glUseProgram(program_); }

}  // namespace render
