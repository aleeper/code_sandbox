/* I have a robot and n other objects on a 2-dimensional plane. The robot is located at the origin. The robot’s sensors have unlimited range but a limited fixed-angle field-of-view φ (e.g, if the robot is pointed north and has a field of view of 30°, it can see between 75° and 105°). The robot cannot move but can turn, and can be instructed to spin to any angle.

Given the (x, y) coordinates of the n objects, determine the heading the robot should turn to to maximize the number of objects that are within its field of view.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <class T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec) {  
  stream << "[";
  typename std::vector<T>::const_iterator iter = vec.cbegin();
  while (iter != vec.cend()) {
      const T& value = *iter; 
      stream << value;
      iter++;
      if (iter != vec.cend()) {
        stream << ", ";
      }
  }
  stream << "]";
  return stream;
}

struct Point {
  double x;
  double y;
  
};

std::ostream& operator<<(std::ostream& stream, const Point& p) {  
  stream << "[";
  stream << p.x << ", " << p.y;
  stream << "]";
  return stream;
}

std::vector<double> getAngles(const std::vector<Point>& points) {
  std::vector<double> angles;
  angles.reserve(points.size());
  for (const Point& point : points) {
    if (point.x == 0 && point.y == 0) {
      continue; 
    }
    double angle = atan2(point.y, point.x) * 180 / M_PI;
    angles.push_back(angle);
  } 
  return angles;
}

double getBestAngle(const std::vector<Point>& points, double fov) {
  // Assume we can't see points at origin.
  
  // get angles
  // sort them
  // find max interval
  std::vector<double> angles = getAngles(points);
  cout << "angles: " << angles << endl;
  std::sort(angles.begin(), angles.end());
  cout << "angles sorted: " << angles << endl;
  
  int original_size = angles.size();
  angles.resize(angles.size() * 2);
  for (size_t i = 0; i < angles.size() / 2; i++) {
    angles[i + original_size] = angles[i] + 360; 
  }
  cout << "angles augmented: " << angles << endl;
  
  
  // find max interval
  int lower_index = 0;
  int current_points = 0;
  int max_points = 0;
  double best_angle = 0;
  
  for (size_t upper_index = 0; upper_index < angles.size(); ++upper_index) {
    current_points++;
    double upper_angle = angles[upper_index];
    double lower_angle = angles[lower_index];
    
    while (upper_angle - lower_angle > fov) {
      lower_index++; 
      lower_angle = angles[lower_index];
      current_points--;
    }
    
    if (current_points > max_points) {
      max_points = current_points;
      best_angle = upper_angle - fov/2;
    }
  }
  cout << "max points: " << max_points << endl;
  
  return best_angle;
}

// To execute C++, please define "int main()"
// (0, 1), (1, 0), (0, 0)
// (60, 1), (30, 1), (1, 30), (0, 30), (-1, 30), (30, -1), (60, -1)
int main() {
  // std::vector<Point> points = {
  //   Point{0, 1},
  //   Point{1, 0},
  //   Point{0, 0}
  // };
  std::vector<Point> points = {
    Point{60, 1},
    Point{30, 1},
    Point{1, 30},
    Point{0, 30},
    Point{-1, 30},
    Point{30, -1},
    Point{60, -1}
  };
  cout << "points: " << points << endl;
  double angle = getBestAngle(points, 30);
  
  cout << "best angle: " << angle << endl;
  
  return 0;
}
