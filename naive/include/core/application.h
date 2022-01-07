#ifndef __NV_APPLICATION_H__
#define __NV_APPLICATION_H__ 1

namespace naive {

  class Application
  {

  public:

    Application();
    Application(const Application&);
    ~Application();

    void run();

    // tmp here...
    static bool application_should_close_;
  private:

    void init();
    void update();
    void shutdown();


  };

}

#endif // !__NV_APPLICATION_H__