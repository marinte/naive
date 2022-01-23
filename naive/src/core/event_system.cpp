#include "core/event_system.h"

namespace naive {

  std::unordered_map<size_t, std::vector<std::unique_ptr<EventCallbackBaseWrapper>>> EventSystem::event_callbacks;

}