#ifndef __NAIVE_EVENT_SYSTEM_H__
#define __NAIVE_EVENT_SYSTEM_H__ 1

#include <unordered_map>
#include <vector>
#include <functional>

#include "core/log.h"

namespace naive {

#define NV_EVENT_TYPE(type)                                       \
    type(){ type_ = k##type##Type; }                            \
  static Type getEventType() { return Type::k##type##Type; }

  struct Event {

    enum Type
    {
      kNoneType = 0,

      // Mouse
      kMouseButtonDownEventType,
      kMouseButtonUpEventType,
      kMouseMovedEventType,
      kMouseScrolledEventType,

      // Keyboard
      kKeyDownEventType,
      kKeyPressedEventType,
      kKeyUpEventType,

      // Application
      kWindowClosedEventType

    };

    inline const Type& getType() const { return type_; }

  protected:

    Type type_;

  };


  struct EventCallbackBaseWrapper {

    virtual void operator()(const Event*) = 0;

  };

  template<typename T>
  struct EventCallbackWrapper : EventCallbackBaseWrapper {

    EventCallbackWrapper(std::function<void(const T&)> callback) : callback_(callback) {}

    std::function<void(const T&)> callback_;

    void operator()(const Event* incoming_event) {
      callback_(*static_cast<const T*>(incoming_event));
    }

  };



  class EventSystem {

  public:

    static void DispachEvent(const Event& incoming_event) {

      NAIVE_DEBUG("{0}", incoming_event.getType());

      naive::Event::Type id = incoming_event.getType();

      for (int i = 0; i < event_callbacks[id].size(); ++i) {
        (*event_callbacks[id][i])(&incoming_event);
      }

    }

    template<typename T>
    static void BindEvent(std::function<void(const T&)> event_callback) {

      NAIVE_DEBUG("Binding Event: {0}", typeid(T).name());
      event_callbacks[T::getEventType()].emplace_back(std::move(std::make_unique<EventCallbackWrapper<T>>(event_callback)));

    }

  private:

    static std::unordered_map<size_t /*event*/, std::vector<std::unique_ptr<EventCallbackBaseWrapper>> /*callback*/> event_callbacks;

  };

}

#endif // !__NAIVE_EVENT_SYSTEM_H__
