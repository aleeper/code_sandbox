// #include "leeper_helpers.h"
// #include "scoped_timer.h"
// #include <chrono>

#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ********************************
// Recursive Solution
// ********************************
void getCombinationsRecursive(const vector<vector<int>>& values, int row_index,
    vector<int>& combo, vector<vector<int>>& all_combinations) {

  const vector<int>& current_row = values[row_index];
  for (int value : current_row) {
    combo.push_back(value);
    if (row_index < values.size() - 1) {
      getCombinationsRecursive(values, row_index + 1, combo, all_combinations);
    } else {
      all_combinations.push_back(combo);
    }
    combo.pop_back();
  }
}

vector<vector<int>> getCombinationsByRecursion(const vector<vector<int>>& values) {
  vector<vector<int>> combinations;
  if (!values.empty()) {
    vector<int> combo;
    combo.reserve(values.size());
    getCombinationsRecursive(values, 0, combo, combinations);
  }
  return combinations;
}

// ********************************
// Nth-combination Solution
// ********************************
vector<int> makeCombination(const vector<vector<int>>& values, int index) {
  vector<int> combo;
  combo.reserve(values.size());
  int divisor = 1;
  for (int row_index = 0; row_index < values.size(); row_index++) {
    const vector<int>& current_row = values[row_index];
    int column_index = (index / divisor) % current_row.size();
    divisor *= current_row.size();
    combo.emplace_back(current_row[column_index]);
  }
  return combo;
}

vector<vector<int>> getCombinationsByIndex(const vector<vector<int>>& values) {
  int total_size = 1;
  for (const auto& row : values) {
    total_size *= row.size();
  }

  vector<vector<int>> combinations;
  combinations.reserve(total_size);
  for (int i = 0; i < total_size; i++) {
    combinations.push_back(makeCombination(values, i));
  }
  return combinations;
}


// Helper for printing.
template <class T>
std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<T>>& board) {
  size_t rows = board.size();
  stream << "[";
  for (size_t i = 0; i < rows; i++) {
    size_t columns = board[i].size();
    if (i > 0) {
      stream << " ";
    }
    stream << "[";
    for (size_t j = 0; j < columns; j++) {
        stream << std::setw(0) << board[i][j] << std::setw(0);
        if (j < columns - 1) {
          stream << ", ";
        }
    }
    stream << "]";
    if (i < rows - 1) {
      stream << "\n";
    }
  }
  stream << "]";
  return stream;
}

int main() {
  vector<vector<int>> values = {
    {1, 2, 3},
    {4, 5},
    {6, 7, 8, 9},
  };

  cout << "values:\n" << values << endl;
  vector<vector<int>> combinations = getCombinationsByIndex(values);
  // combinations = getCombinationsByRecursion(values);

  cout << "Combinations:\n" << combinations << endl;

  return 0;
}

// int main() {
//   vector<vector<int>> values = {
//     {1, 2, 3},
//     {4, 5},
//     {6, 7, 8, 9},
//     // {1, 2, 3, 4, 5, 6}
//   };

//   cout << "values:\n" << values << endl;
//   auto start = std::chrono::high_resolution_clock::now();
//   constexpr int kNumIterations = 1000;
//   vector<vector<int>> combinations;
//   double time = 0;
//   {
//     ScopedTimer timer(&time);
//     for (int i = 0; i < kNumIterations; i++) {
//       // combinations = getCombinationsByIndex(values);
//       combinations = getCombinationsByRecursion(values);
//     }
//   }

//   cout << "Combinations:\n" << combinations << endl;

//   cout << "Calculated " << combinations.size() << " combinations in an average of "
//        << static_cast<int>(time * 1e6 / kNumIterations) << " microseconds." << endl;

//   return 0;
// }