#ifndef __NV_WINDOWS_WINDOW_H__
#define __NV_WINDOWS_WINDOW_H__ 1

#include "core/window.h"

struct GLFWwindow;

namespace naive {

  class Window_ImplWindows : public Window {

  public:

    Window_ImplWindows(const WindowInfo&);
    virtual ~Window_ImplWindows() override;

    virtual void onUpdate() override;

    const inline virtual uint16_t& width() const override { return info_.width_; }
    const inline virtual uint16_t& height() const override { return info_.height_; }
    const inline virtual std::string& title() const override { return info_.title_; }
    const inline virtual bool& hasVsyncEnabled() const override { return info_.vsync_enabled_; }

    virtual void setVsyncEnabled(const bool& vsync) override;
    virtual void setEventCallback(std::function<void(Event)> event_callback) override;

  private:

    void init(const WindowInfo& info);
    void shutdown();

    GLFWwindow* window_instance_;
    static  uint8_t s_instantiated_windows_count_;

  };


}


#endif // !__NV_WINDOWS_WINDOW_H__
