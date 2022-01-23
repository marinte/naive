#ifndef __NV_LOG_H__
#define  __NV_LOG_H__ 1

//TODO: in a future this will be moved to debug class, where profiling and logging is managed.

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/spdlog.h"

#include "minitrace/minitrace.h"

namespace naive {

  class Log {

  public:

    static void init();

    static void shutdown();

  };

}

#define NAIVE_TRACE(c, n) MTR_SCOPE(c, n)
#define NAIVE_DEBUG(...) SPDLOG_TRACE(__VA_ARGS__)
#define NAIVE_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define NAIVE_WARN(...) SPDLOG_WARN(__VA_ARGS__)
#define NAIVE_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define NAIVE_FATAL(...) SPDLOG_CRITICAL(__VA_ARGS__)


#ifdef NV_PLATFORM_WINDOWS
#define NAIVE_ASSERT(condition, ...) if(!(condition)) { SPDLOG_CRITICAL(__VA_ARGS__); __debugbreak(); }
#endif // NV_PLATFORM_WINDOWS

#endif // !__NV_LOG_H__
