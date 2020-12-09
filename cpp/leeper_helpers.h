#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

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

// template <class T>
// std::ostream& operator<<(std::ostream& stream, std::vector<T>& vec) {  
//   stream << "[";  
//   for (size_t i = 0; i < vec.size(); i++) {
//       stream << vec[i];
//       if (i < vec.size() - 1) {
//         stream << ", ";
//       }
//   }
//   stream << "]";
//   return stream;
// }

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

template <class Key, class Value>
std::ostream& operator<<(std::ostream& stream, const std::map<Key, Value>& map) {  
  stream << "{";
  typename std::map<Key, Value>::const_iterator iter = map.begin();
  while (iter != map.end()) {
    stream << "\n  " << iter->first << ": " << iter->second;
    iter++;
    if (iter != map.end()) {
      stream << ", ";
    }
  }
  stream << "\n}";
  return stream;
}

// template <class Key, class Value>
// std::ostream& operator<<(std::ostream& stream, const std::map<Key, Value>& map) {  
//   stream << "{";
//   for (const typename std::map<Key, Value>::value_type& pair : map) {
//       stream << "\n  " << pair.first << ": " << pair.second;
//   }
//   stream << "\n}";
//   return stream;
// }