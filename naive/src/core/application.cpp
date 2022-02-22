#include "core/window.h"
#include "core/application.h"

#include "core/log.h"

#include <functional>
#include <glad/glad.h>


namespace naive {

  Application::Application() {}

  Application::Application(const Application&) {}

  Application::~Application() {}

  void Application::init() {

    NAIVE_TRACE("NV", "Init");
    WindowInfo info;
    info.width_ = 1920;
    info.width_ = 1080;
    info.title_ = "Naive Engine";
    info.vsync_enabled_ = true;

    window_ = std::unique_ptr<Window>(Window::create(info));
    window_->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

    EventSystem::BindEvent<WindowClosedEvent>(std::bind(&Application::onWindowClosed, this, std::placeholders::_1));

  }

  void Application::update() {
    NAIVE_TRACE("NV", "Update");
  }

  void Application::onEvent(Event incoming_event) {

    EventSystem::DispachEvent(incoming_event);

  }

  void Application::onWindowClosed(const WindowClosedEvent& incoming_event) {

    application_should_close_ = true;

  }

  void Application::shutdown() {
    NAIVE_TRACE("NV", "Shut Down");
  }

  void Application::run() {

    naive::Log::init();
    init();


    glClearColor(0.35f, 0.95f, 0.9f, 1.0f);
    while (!application_should_close_) {

      glClear(GL_COLOR_BUFFER_BIT);
      //int width, height;
      //glfwGetFramebufferSize(window, &width, &height);


      //double time = glfwGetTime();

      update();
      window_->onUpdate();

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
