#include <vector>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

template <class T>
std::ostream& operator<<(std::ostream& stream, std::vector<std::vector<T>>& board) {  
  size_t rows = board.size();
  stream << "[";
  for (size_t i = 0; i < rows; i++) {
    size_t columns = board[i].size();
    if (i > 0) {
      stream << " ";
    }
    stream << "[";
    for (size_t j = 0; j < columns; j++) {
        cout << std::setw(0) << board[i][j] << std::setw(0);
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

template <class T>
std::ostream& operator<<(std::ostream& stream, std::vector<T>& vec) {  
  stream << "[";  
  for (size_t i = 0; i < vec.size(); i++) {
      cout << vec[i];
      if (i < vec.size() - 1) {
        stream << ", ";
      }
  }
  stream << "]";
  return stream;
}