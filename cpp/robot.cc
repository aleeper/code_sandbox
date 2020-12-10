#include "leeper_helpers.h"

#include <iostream>
#include <vector>
#include <queue>

struct Point {
  bool operator==(const Point& rhs) {
    return row == rhs.row && col == rhs.col;
  }
  int row;
  int col;
};

struct PathNode {
  Point p;
  int cost;
  int estimated_cost;
};

std::ostream& operator<<(std::ostream& stream, const Point& p) {
  stream << "[" << p.row << ", " << p.col << "]";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const PathNode& n) {
  stream << "PathNode: " << n.p << ", cost: " << n.cost
      << ", estimated_cost: " << n.estimated_cost;
  return stream;
}

int getManhattanDistance(const Point& p1, const Point& p2) {
  return std::abs(p1.row - p2.row) + std::abs(p1.col - p2.col);
}


int getMinPathCost(const std::vector<std::vector<int>>&  grid, const Point& starting_position) {
  using std::cout;
  using std::endl;
  if (grid.size() == 0 || grid[0].size() == 0) {
    return -1; 
  }
  Point goal = Point{static_cast<int>(grid.size()) - 1, static_cast<int>(grid[0].size()) - 1};//
  
  auto comp_fn = [](const PathNode& node1, const PathNode& node2) {
    // return node1.estimated_cost > node2.estimated_cost;
    return node1.cost > node2.cost;
  };
  
  std::priority_queue<PathNode, std::vector<PathNode>, decltype(comp_fn) > q(comp_fn);
  
  q.push(PathNode{starting_position, 0, getManhattanDistance(starting_position, goal)});
  int final_cost = 0;
  int num_nodes_expanded = 0;
  while (!q.empty()) {
    num_nodes_expanded++;
    PathNode n = q.top();
    cout << n << endl;
    Point p = n.p;
    int cost = n.cost;
    int estimated_cost = n.estimated_cost; 
    q.pop();

    // "Visit" this cell by adding its cost.
    cost += grid[p.row][p.col];
    estimated_cost = cost + getManhattanDistance(p, goal);
    // cout << "new cost: " << cost << endl;
    if (p == goal) {
      final_cost = cost;
      break;
    }
    
    if (p.row < static_cast<int>(grid.size()) - 1) {
      q.push(PathNode{Point{p.row + 1, p.col}, cost, estimated_cost});
    }
    if (p.col < static_cast<int>(grid[0].size()) - 1) {
      q.push(PathNode{Point{p.row, p.col + 1}, cost, estimated_cost});
    }
  }
  cout << "Cost " << final_cost << ", expanded " << num_nodes_expanded << " nodes." << endl;
  return final_cost;
}



// To execute C++, please define "int main()"
int main() {
  
  std::vector<std::vector<int>> grid = {
      {1, 2, 2, 1},
      {9, 1, 5, 1},
      {8, 1, 5, 1}
    };
  
  std::cout << "grid:\n" << grid << std::endl;
  
  int cost = getMinPathCost(grid, Point{0, 0});
  std::cout << "cost: " << cost << std::endl;
  
  return 0;
}


/* 
Given a m x n grid filled with non-negative numbers representing the cost,
there is a robot at the top left corner. Find a path for the robot to the
bottom right corner which minimizes the sum of total cost along its path.

Note: The robot can only move either down or right at any point in time.

For example, for 
1, 2, 2
7, 1, 5
8, 1, 1

returns 6.

Possible helper:
// Returns the minimum element in a vector of positive doubles.
double FindMin(const vector<double> &nums){
  if(nums.empty()) return -1.0;
  double res=nums[0];
  for(const auto num:nums){
    if(num<res){
      res=num;
    }
  }
  return res;
}

 */