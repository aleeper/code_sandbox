#include "leeper_helpers.h"

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;


struct Point {
  double x;
  double y;
};

std::ostream& operator<<(std::ostream& stream, const Point& p) {
  stream << "[" << p.x << ", " << p.y << "]";
  return stream;
}


double distanceSq(const Point& a, const Point& b) {
  double diffX = a.x - b.x;
  double diffY = a.y - b.y;
  return diffX * diffX + diffY * diffY;
}

std::vector<Point> findKClosest(const std::vector<Point>& points,
                                int k, const Point& target) {
  auto comp = [&](const Point& left, const Point& right) {
    return distanceSq(left, target) < distanceSq(right, target);
  };
  std::priority_queue<Point, std::vector<Point>, decltype(comp) > q(comp);

  for (const Point& point : points) {
    q.push(point);
    if (q.size() > k) {
      q.pop();
    }
  }

  std::vector<Point> result;
  result.reserve(q.size());
  while (!q.empty()) {
    result.push_back(q.top());
    q.pop();
  }
  return result;
}

int main() {
  std::vector<Point> points = {{1, 3}, {0, 0}, {-1, 5}, {0.1, 1.2}, {10, 11}};
  cout << "Input points: " << points << endl;
  Point target{0, 1};
  cout << "Target point: " << target << endl;
  std::vector<Point> closest = findKClosest(points, 2, target);
  cout << "Closest points: " << closest << endl;

  return 0;
}