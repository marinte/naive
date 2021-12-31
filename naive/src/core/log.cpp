#include "core/log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/async.h"

namespace naive {

  void Log::init() {

    mtr_init("trace.json");
    MTR_META_PROCESS_NAME("minitrace_test");
    MTR_META_THREAD_NAME("main thread");

    std::shared_ptr<spdlog::logger> naive_logger;

    // Formatting: https://github.com/gabime/spdlog/wiki/3.-Custom-formattings
    spdlog::set_pattern("%^[%T][%@][%!]: %v%$");
    naive_logger = spdlog::stdout_color_mt<spdlog::async_factory>("Naive");
    naive_logger->set_level(spdlog::level::trace);

    spdlog::set_default_logger(naive_logger);

  }

  void Log::shutdown() { 
    mtr_flush(); 
    mtr_shutdown();
  }

}