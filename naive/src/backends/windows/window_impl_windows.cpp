#include "core/log.h"
#include "backends/windows/window_impl_windows.h"
#include "core/application.h"

namespace naive {

  namespace Internal {

    void error_callback(int error, const char* description)
    {
      NAIVE_ERROR("ErrorCode: {0}: {1}", error, description);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        naive::Application::application_should_close_ = true;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
      }
    }

  }

  uint8_t Window_ImplWindows::s_instantiated_windows_count_ = 0;

  Window* Window::create(const WindowInfo& window_info) { return new Window_ImplWindows(window_info); }

  Window_ImplWindows::Window_ImplWindows(const WindowInfo& info) { init(info); }

  Window_ImplWindows::~Window_ImplWindows() { shutdown(); }

  void Window_ImplWindows::init(const WindowInfo& info) {

    NAIVE_INFO("Creating a Window: [width: {0}, height: {1}, title: {2}, vsync: {3}]", info.width_, info.height_, info.title_, info.vsync_enabled_);

    if (!s_instantiated_windows_count_++) {

      NAIVE_INFO("Initializing GLFW Backend.");

      int status = glfwInit();
      NAIVE_ASSERT(status, "Failed initializing glfw");

    }

    NAIVE_DEBUG("Windows created: {0}", s_instantiated_windows_count_);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window_instance_ = glfwCreateWindow(info_.width_,
      info_.height_, info_.title_.c_str(), NULL, NULL);

    glfwMakeContextCurrent(window_instance_);

    glfwSetErrorCallback(Internal::error_callback);
    glfwSetKeyCallback(window_instance_, Internal::key_callback);

  }

  void Window_ImplWindows::shutdown() {

    glfwDestroyWindow(window_instance_);

    if (!--s_instantiated_windows_count_) {
      NAIVE_INFO("Terminating GLFW Backend");
      glfwTerminate();
    }

  }

  void Window_ImplWindows::setVsyncEnabled(const bool& vsync) {

    int interval = vsync ? 1 : 0;
    glfwSwapInterval(interval);

    info_.vsync_enabled_ = vsync;

  }

  void Window_ImplWindows::onUpdate() {

    glfwSwapBuffers(window_instance_);
    glfwPollEvents();

  }

}