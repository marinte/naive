#ifndef __NV_APPLICATION_H__
#define __NV_APPLICATION_H__ 1

#include "core/event_system.h"
#include "core/events/application_event.h"

namespace naive {

  class Application
  {

  public:

    Application();
    Application(const Application&);
    ~Application();

    void run();

  private:

    void init();
    void update();
    void shutdown();
    void onEvent(Event incoming_event);

    void onWindowClosed(const WindowClosedEvent& incoming_event);

    std::unique_ptr<Window> window_;
    bool application_should_close_ = false;

  };

}

#endif // !__NV_APPLICATION_H__