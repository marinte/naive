#include "core/log.h"

#include <filesystem>
#include <iostream>


void test() {

  MTR_SCOPE("NV", "Application");
  const int a = 500;
  std::vector<double> test_vector;
  test_vector.reserve(a * a);
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < a; ++j) {

      double b = sqrt(i) * sqrt(j);
      test_vector.emplace_back(b);
    }

  }

  for (size_t i = 0; i < test_vector.size(); ++i) {
    test_vector[i] = sqrt(test_vector[i]);
  }

  test_vector.clear();

}

int main(int argc, char** argv) {

  naive::Log::init();


  std::cout << std::filesystem::current_path() << std::endl;
  test();

  NAIVE_DEBUG("This is a DEBUG test {0}", 10);
  NAIVE_INFO("This is a INFO test {0}", 10);
  NAIVE_WARN("This is a WARN test {0}", 10);
  NAIVE_ERROR("This is a ERROR test {0}", 10);
  NAIVE_FATAL("This is a CRITICAL test {0}", 10);

  naive::Log::shutdown();

  return 0;

}