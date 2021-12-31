#ifndef __NV_LOG_H__
#define  __NV_LOG_H__ 1

#include <memory>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/spdlog.h"

namespace naive {

  struct Log {

    static void init();

  };


}

#define NAIVE_TRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define NAIVE_DEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define NAIVE_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define NAIVE_WARN(...) SPDLOG_WARN(__VA_ARGS__)
#define NAIVE_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define NAIVE_FATAL(...) SPDLOG_CRITICAL(__VA_ARGS__)


#endif // !__NV_LOG_H__