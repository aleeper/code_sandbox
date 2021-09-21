#include <iostream>
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

// Helper function -- completely optional.
std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
  stream << "[";
  stream << v.x << ", " << v.y << ", " << v.z;
  stream << "]";
  return stream;
}

// Helper function -- completely optional.
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
  double remaining_length = t * trajectory_length;

  for (size_t i = 0; i < points.size() - 1; ++i) {
    double segment_length = (points[i+1] - points[i]).norm();
    if (segment_length > remaining_length) {
      double segment_t = remaining_length / segment_length;
      return (1-segment_t) * points[i] + segment_t * points[i+1];
    } else {
      remaining_length -= segment_length;
    }
  }
  return points.back();
}

int main() {
  vector<Vec3> points = {
      Vec3{0, 0, 0},Vec3{1, 0, 0},Vec3{1, 1, 0},Vec3{3, 1, 0}
    };
  cout << "points: " << points << endl;
  cout << "t = 0.0: " << interpolateTrajectory(points, 0.0) << endl;
  cout << "t = 0.2: " << interpolateTrajectory(points, 0.2) << endl;
  cout << "t = 0.4: " << interpolateTrajectory(points, 0.4) << endl;
  cout << "t = 0.6: " << interpolateTrajectory(points, 0.6) << endl;
  cout << "t = 0.8: " << interpolateTrajectory(points, 0.8) << endl;
  cout << "t = 1.0: " << interpolateTrajectory(points, 1.0) << endl;

  return 0;
}
