#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct Vec3 {
  double x;
  double y;
  double z;

  double dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
  }
  double norm() const {
    return std::sqrt(this->dot(*this));
  }
};

Vec3 operator+(const Vec3& a, const Vec3& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 operator-(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 operator*(const double s, const Vec3& a) {
    return {s * a.x, s * a.y, s * a.z};
}

std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
  stream << "[";
  stream << v.x << ", " << v.y << ", " << v.z;
  stream << "]";
  return stream;
}

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

Vec3 interpolateTrajectory(const std::vector<Vec3>& points, double t) {
  // Calculate length.
  double trajectory_length = 0;
  for (size_t i = 0; i < points.size() - 1; ++i) {
    trajectory_length += (points[i+1] - points[i]).norm();
  }
  cout << "trajectory_length: " << trajectory_length << endl;
  double interpolated_length = t * trajectory_length;


  for (size_t i = 0; i < points.size() - 1; ++i) {
    double this_segment = (points[i+1] - points[i]).norm();
    if (this_segment > interpolated_length) {
      double new_t = interpolated_length / this_segment;
      return (1-new_t) * points[i] + new_t * points[i+1];
    } else {
      interpolated_length -= this_segment;
    }
  }
  cout << "BADNESS!" << endl;

}

// To execute C++, please define "int main()"
int main() {

  vector<Vec3> points = {
    Vec3{0, 0, 0},
    Vec3{1, 0, 0},
    Vec3{1, 1, 0},
    Vec3{3, 1, 0},
  };
  cout << "points: " << points << endl;
  cout << "t = 0.00: " << interpolateTrajectory(points, 0.00) << endl;
  cout << "t = 0.25: " << interpolateTrajectory(points, 0.25) << endl;
  cout << "t = 0.33: " << interpolateTrajectory(points, 0.33) << endl;
  cout << "t = 0.50: " << interpolateTrajectory(points, 0.50) << endl;
  cout << "t = 0.66: " << interpolateTrajectory(points, 0.66) << endl;
  cout << "t = 0.75: " << interpolateTrajectory(points, 0.75) << endl;
  cout << "t = 1.00: " << interpolateTrajectory(points, 1.00) << endl;


  return 0;
}
