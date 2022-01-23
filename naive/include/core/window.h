#ifndef __NV_WINDOW_H__
#define __NV_WINDOW_H__ 1

#include <stdint.h>
#include <string>
#include <memory>
#include <functional>

#include "core/event_system.h"

namespace naive {

  struct WindowInfo {

    WindowInfo(
      const std::string& title = "Naive Engine",
      const uint16_t& width = 1920,
      const uint16_t& height = 1080,
      const bool& vsync_enabled = true,
      const std::function<void(Event)> event_callback = nullptr
    ) :
      title_(title), width_(width), height_(height),
      vsync_enabled_(vsync_enabled), event_callback_(event_callback)
    {}

    std::string title_;
    uint16_t width_;
    uint16_t height_;
    bool vsync_enabled_;
    std::function<void (Event)> event_callback_;

  };

  class Window {

  public:

    Window() = default;
    Window(const Window&) = default;
    virtual ~Window() = default;

    virtual void onUpdate() = 0;

    const virtual uint16_t& width() const = 0;
    const virtual uint16_t& height() const = 0;
    const virtual std::string& title() const = 0;
    const virtual bool& hasVsyncEnabled() const = 0;

    virtual void setVsyncEnabled(const bool& vsync) = 0;

    virtual void setEventCallback(std::function<void(Event)> event_callback) = 0;

    static Window* create(const WindowInfo& window_info = WindowInfo());

  protected:

    WindowInfo info_;

  };

}

#endif // !__NV_WINDOW_H__
