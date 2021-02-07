#include <chrono>
#include <iostream>

class ScopedTimer {

 public:
  ScopedTimer(double* output)
    : start_(std::chrono::high_resolution_clock::now()),
      output_(output) {

  }
  ~ScopedTimer() {
    auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<double>(stop - start_);
    auto duration = std::chrono::duration<double>(stop - start_);
    // std::cout << "Elapsed time: " << duration.count() << " seconds." << std::endl;
    *output_ = duration.count();
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_;
  double* output_;
};