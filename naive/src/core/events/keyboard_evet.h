#ifndef __NAIVE_KEYBOARD_EVENT_H__
#define __NAIVE_KEYBOARD_EVENT_H__ 1

#include "core/event_system.h"

namespace naive {

  struct KeyDownEvent : public Event
  {
    
    NV_EVENT_TYPE(KeyDownEvent);

    int key;

  };

  struct KeyPressedEvent : public Event
  {

    NV_EVENT_TYPE(KeyPressedEvent);

    int key;

  };

  struct KeyUpEvent : public Event
  {

    NV_EVENT_TYPE(KeyUpEvent);

    int key;

  };

}


#endif // !__NAIVE_KEYBOARD_EVENT_H__
