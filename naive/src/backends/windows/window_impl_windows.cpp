#include "core/log.h"
#include "backends/windows/window_impl_windows.h"
#include "core/application.h"

#include "core/events/mouse_event.h"
#include "core/events/keyboard_evet.h"
#include "core/events/application_event.h"

// Game Engine Architecture 3rd Edition - Page 1137

//#define HANDLE_EVENT(incoming_event)                                                  
#define HANDLE_EVENT(incoming_event)                                                  \
       WindowInfo& info = *static_cast<WindowInfo*>(glfwGetWindowUserPointer(window));  \
       info.event_callback_(std::move(incoming_event))

namespace naive {

  //   namespace Internal {
  // 
  //     void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
  //     {
  //       if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
  //         naive::Application::application_should_close_ = true;
  //         //glfwSetWindowShouldClose(window, GLFW_TRUE);
  //       }
  //     }
  // 
  //   }

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

    glfwSetWindowUserPointer(window_instance_, &info_);

    //Setup GLFW callbacks.

    // Error
    glfwSetErrorCallback([](int error, const char* description) {

      NAIVE_ERROR("ErrorCode: {0}: {1}", error, description);

    });

    // Mouse
    glfwSetCursorPosCallback(window_instance_, [](GLFWwindow* window, double xpos, double ypos) {

      MouseMovedEvent mouse_moved_event;
      mouse_moved_event.x_position = xpos;
      mouse_moved_event.y_position = ypos;

      HANDLE_EVENT(mouse_moved_event);

    });

    glfwSetMouseButtonCallback(window_instance_, [](GLFWwindow* window, int button, int action, int mods) {

      if (action == GLFW_PRESS) {

        MouseButtonDownEvent mouse_button_down_event;
        mouse_button_down_event.button = button;

        HANDLE_EVENT(mouse_button_down_event);

      }
      else if (action == GLFW_RELEASE) {

        MouseButtonUpEvent mouse_button_up_event;
        mouse_button_up_event.button = button;

        HANDLE_EVENT(mouse_button_up_event);
      }


    });

    glfwSetScrollCallback(window_instance_, [](GLFWwindow* window, double xoffset, double yoffset) {

      MouseScrolledEvent mouse_scrolled_event;
      mouse_scrolled_event.x_offset = xoffset;
      mouse_scrolled_event.y_offset = yoffset;

      HANDLE_EVENT(mouse_scrolled_event);

    });

    // Keyboard
    glfwSetKeyCallback(window_instance_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

      if (action == GLFW_PRESS) {

        KeyDownEvent key_down_event;
        key_down_event.key = key;

        HANDLE_EVENT(key_down_event);



      }
      else if (action == GLFW_REPEAT) {

        KeyPressedEvent key_pressed_event;
        key_pressed_event.key = key;

        HANDLE_EVENT(key_pressed_event);

      }
      else if (action == GLFW_RELEASE) {

        KeyUpEvent key_up_event;
        key_up_event.key = key;

        HANDLE_EVENT(key_up_event);

      }

    });

    // Application
    glfwSetWindowCloseCallback(window_instance_, [](GLFWwindow* window) {

      WindowClosedEvent window_closed_event;
      HANDLE_EVENT(window_closed_event);

    });

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

  void Window_ImplWindows::setEventCallback(std::function<void(Event)> event_callback) {

    info_.event_callback_ = event_callback;

  }

  void Window_ImplWindows::onUpdate() {

    glfwSwapBuffers(window_instance_);
    glfwPollEvents();

  }

#undef HANDLE_EVENT

}