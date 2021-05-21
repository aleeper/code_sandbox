#include "leeper_helpers.h"

#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using std::cout;
using std::endl;

class Shape {
 public:
  virtual ~Shape() {
    cout << "Shape destructor: " << id_ << endl;
  }
  virtual double getArea() const = 0;
  virtual void setId(const std::string& id) {
    id_ = id;
  }

 protected:
  std::string id_;
};

class Rectangle : public Shape {
 public:
  Rectangle() : Rectangle(0, 0) {}
  Rectangle(double width, double height)
    : width_(width), height_(height) {}

  Rectangle(const Rectangle& other) = delete;
  Rectangle& operator=(const Rectangle& other) = delete;

  ~Rectangle() {
    cout << "Rectangle destructor: " << id_ << endl;
  }

  double getArea() const override {
    return width_ * height_;
  }

  double width() const { return width_; }
  double height() const { return height_; }

 protected:
  double width_;
  double height_;
};

std::ostream& operator<<(std::ostream& stream, const Rectangle& r) {
  stream << "Rectangle: width = " << r.width() << ", height = " << r.height();
  return stream;
}

int main() {
  Rectangle r(2, 3);
  r.setId("r");
  cout << r << endl;
  cout << "area = " << r.getArea() << endl;

  auto rect2 = std::make_unique<Rectangle>(9, 4);
  rect2->setId("rect2");
  cout << *rect2 << endl;
  cout << "area = " << rect2->getArea() << endl;
  cout << "rect2: " << rect2.get() << endl;

  std::unique_ptr<Rectangle> rect3;
  rect3 = std::move(rect2);

  cout << "rect2: " << rect2.get() << endl;
  cout << "rect3: " << rect3.get() << endl;

  rect2.reset();
  rect3.reset();

  cout << "All done!" << endl;

  return 0;
}