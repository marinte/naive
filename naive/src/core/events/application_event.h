#ifndef __NAIVE_APPLICATION_EVENT_H__
#define __NAIVE_APPLICATION_EVENT_H__ 1

#include "core/event_system.h"

namespace naive {

  struct WindowClosedEvent : public Event {

    NV_EVENT_TYPE(WindowClosedEvent);

  };

}

#endif // !__NAIVE_APPLICATION_EVENT_H__
