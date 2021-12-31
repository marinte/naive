#include "core/log.h"

int main(int argc, char** argv) {

  naive::Log::init();

  NAIVE_TRACE("This is a TRACE test {0}", 10);
  NAIVE_DEBUG("This is a DEBUG test {0}", 10);
  NAIVE_INFO("This is a INFO test {0}", 10);
  NAIVE_WARN("This is a WARN test {0}", 10);
  NAIVE_ERROR("This is a ERROR test {0}", 10);
  NAIVE_FATAL("This is a CRITICAL test {0}", 10);

  return 0;

}