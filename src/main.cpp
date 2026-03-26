#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

constexpr int Width = 1280;
constexpr int Height = 800;

int main() {

  if (!glfwInit()) {
    std::cout << "GLFW INIT FAILED \n";
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(Width, Height, "VOXEL GAME", nullptr, nullptr);

  if (!window) {
    std::cout << "Windows failed to create \n";
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD\n";
    return -1;
  }

  std::cout << glGetString(GL_VENDOR) << "\n";
  std::cout << glGetString(GL_RENDERER) << "\n";
  std::cout << glGetString(GL_VERSION) << "\n";

  glEnable(GL_DEPTH_TEST);

  glViewport(0, 0, Width, Height);

  // Main loop
  while (!glfwWindowShouldClose(window)) {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
