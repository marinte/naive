#include "core/input.h"
#include "core/application.h"

#include <GLFW/glfw3.h>

namespace naive {

  // Keys
  bool Input::isKeyDown(const KeyCode key_code) {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    static int previous_state = GLFW_RELEASE;
    int state = glfwGetKey(window, static_cast<int>(key_code));

    if (previous_state == GLFW_RELEASE && state == GLFW_PRESS) {

      previous_state = state;
      return true;

    }

    previous_state = state;
    return false;

  }

  bool Input::isKeyPressed(const KeyCode key_code) {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    static int previous_state = GLFW_RELEASE;
    int state = glfwGetKey(window, static_cast<int>(key_code));

    if (previous_state == GLFW_PRESS && state == GLFW_PRESS) {

      previous_state = state;
      return true;

    }

    previous_state = state;
    return false;

  }

  bool Input::isKeyUp(const KeyCode key_code) {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    static int previous_state = GLFW_RELEASE;
    int state = glfwGetKey(window, static_cast<int>(key_code));

    if (previous_state == GLFW_PRESS && state == GLFW_RELEASE) {

      previous_state = state;
      return true;

    }

    previous_state = state;
    return false;

  }

  // Mouse Buttons
  bool Input::isMouseButtonDown(const MouseButton mouse_button) {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    static int previous_state = GLFW_RELEASE;
    int state = glfwGetMouseButton(window, static_cast<int>(mouse_button));

    if (previous_state == GLFW_RELEASE && state == GLFW_PRESS) {

      previous_state = state;
      return true;

    }

    previous_state = state;
    return false;

  }

  bool Input::isMouseButtonPressed(const MouseButton mouse_button) {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    static int previous_state = GLFW_RELEASE;
    int state = glfwGetMouseButton(window, static_cast<int>(mouse_button));

    if (previous_state == GLFW_PRESS && state == GLFW_PRESS) {

      previous_state = state;
      return true;

    }

    previous_state = state;
    return false;

  }

  bool Input::isMouseButtonUp(const MouseButton mouse_button) {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    static int previous_state = GLFW_RELEASE;
    int state = glfwGetMouseButton(window, static_cast<int>(mouse_button));

    if (previous_state == GLFW_PRESS && state == GLFW_RELEASE) {

      previous_state = state;
      return true;

    }

    previous_state = state;
    return false;

  }

  // Mouse Position
  glm::vec2 Input::getMousePosition() {

    GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
    double x_position, y_position;
    glfwGetCursorPos(window, &x_position, &y_position);

    return glm::vec2(x_position, y_position);

  }

  float Input::getMouseX() { return getMousePosition().x; }
  float Input::getMouseY() { return getMousePosition().y; }

}