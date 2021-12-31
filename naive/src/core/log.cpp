#include "core/log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/async.h"


namespace naive {

  void Log::init() {

    std::shared_ptr<spdlog::logger> naive_logger;

    // Formatting: https://github.com/gabime/spdlog/wiki/3.-Custom-formattings
    spdlog::set_pattern("%^[%T][%@][%!]: %v%$");
    naive_logger = spdlog::stdout_color_mt<spdlog::async_factory>("Naive");
    naive_logger->set_level(spdlog::level::trace);

    spdlog::set_default_logger(naive_logger);

  }

}