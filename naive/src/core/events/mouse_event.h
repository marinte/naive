#ifndef __NAIVE_MOUSE_EVENT_H__
#define __NAIVE_MOUSE_EVENT_H__ 1

#include "core/event_system.h"

namespace naive {

  struct MouseButtonDownEvent : public Event {

    NV_EVENT_TYPE(MouseButtonDownEvent);

    int button;

  };

  struct MouseButtonUpEvent : public Event {

    NV_EVENT_TYPE(MouseButtonUpEvent);

    int button;

  };

  struct MouseMovedEvent : public Event {

    NV_EVENT_TYPE(MouseMovedEvent);

    double x_position;
    double y_position;

  };

  struct MouseScrolledEvent : public Event {

    NV_EVENT_TYPE(MouseScrolledEvent);

    double x_offset;
    double y_offset;

  };

}

#endif // !__NAIVE_MOUSE_EVENT_H__
