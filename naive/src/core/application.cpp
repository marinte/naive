#include "core/window.h"
#include "core/application.h"

#include "core/log.h"


namespace naive {

  bool Application::application_should_close_ = false;

  Application::Application() {}

  Application::Application(const Application&) {}

  Application::~Application() {}

  void Application::init() {
    NAIVE_TRACE("NV", "Init");
  }

  void Application::update() {
    NAIVE_TRACE("NV", "Update");
  }

  void Application::shutdown() {
    NAIVE_TRACE("NV", "Shut Down");
  }

  void Application::run() {

    naive::Log::init();
    init();

    WindowInfo info;
    info.width_ = 1920;
    info.width_ = 1080;
    info.title_ = "Naive Engine";
    info.vsync_enabled_ = true;
    std::unique_ptr<Window> window = std::unique_ptr<Window>(Window::create(info));

    while (!application_should_close_) {

      //int width, height;
      //glfwGetFramebufferSize(window, &width, &height);


      //double time = glfwGetTime();

      update();
      window->onUpdate();

    }


    shutdown();
    naive::Log::shutdown();

  }

}


//TODO: this will be in entry point class in a future.
int main(int argc, char** argv) {

  naive::Application app;
  app.run();

  return 0;
}