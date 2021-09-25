#include <iostream>
#include <memory>

#include <Eigen/Core>

using namespace std;

struct Foo {
  Foo(int v) : value(v) {}

  int value = 0;
};

typedef Eigen::Matrix<std::unique_ptr<Foo>, Eigen::Dynamic, Eigen::Dynamic> CellMatrix;

int main() {
  CellMatrix c(3, 5);
  c(0, 0) = std::make_unique<Foo>(8);
  c(1, 0) = std::make_unique<Foo>(6);
  c(0, 2) = std::make_unique<Foo>(7);
  c(2, 4) = std::make_unique<Foo>(5);
  c(2, 1) = std::make_unique<Foo>(3);
  c(1, 3) = std::make_unique<Foo>(0);
  c(1, 2) = std::make_unique<Foo>(9);

  cout << "cells:\n" << endl;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 5; col++) {
      const auto& ptr = c(row, col);
      if (ptr) {
        cout << ptr->value << " ";
      } else {
        cout << "- ";
      }

    }
    cout << endl;
  }

  return 0;
}