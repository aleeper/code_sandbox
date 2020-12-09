#include "leeper_helpers.h"

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;

struct Point {
  int x;
  int y;
};

std::ostream& operator<<(std::ostream& stream, const Point& p) {
  stream << "[" << p.x << ", " << p.y << "]";
  return stream;
}

vector<vector<int>> createDistanceMap(
    const vector<std::string>& board,
    const Point& point) {
  vector<vector<int>> distances;
  for (auto& row : board) {
    distances.push_back(std::vector<int>(row.size(), -1));
  }

  std::queue<std::pair<int, Point>> q;
  q.push(std::make_pair(0, point));

  while (!q.empty()) {
    int distance = q.front().first;
    Point p = q.front().second;
    q.pop();
    // cout << "Visiting: " << p << endl;
    char cell = board[p.y][p.x];
    int& distance_entry = distances[p.y][p.x];
    if (distance_entry >= 0 || cell == '#') {
      continue;
    }
    distance_entry = distance;
    q.push(std::make_pair(distance + 1, Point{p.x + 1, p.y}));
    q.push(std::make_pair(distance + 1, Point{p.x - 1, p.y}));
    q.push(std::make_pair(distance + 1, Point{p.x, p.y + 1}));
    q.push(std::make_pair(distance + 1, Point{p.x, p.y - 1}));
  }
  return distances;
}


int main() {
  using std::vector;

  vector<std::string> board = {
    "#########",
    "#   # * #",
    "#   #   #",
    "#       #",
    "#########"
  };

  auto distances = createDistanceMap(board, Point{1, 2});

  cout << "distances:\n" << distances << endl;

  return 0;
}