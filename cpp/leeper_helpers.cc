#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>    // std::remove_if

using std::cout;
using std::endl;
using std::vector;

template <class T>
std::ostream& operator<<(std::ostream& stream, vector<vector<T>>& board) {  
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
std::ostream& operator<<(std::ostream& stream, vector<T>& vec) {  
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

// bool IsOdd (int i) { return ((i%2)==1); }

void removeIfArray() {
  int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

  // bounds of range:
  int* pbegin = myints;                          // ^
  int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

  pend = std::remove_if(pbegin, pend, [](int i) { return (i%2)==1; });   // 2 4 6 8 ? ? ? ? ?
                                                 // ^       ^
  std::cout << "the range contains:";
  for (int* p=pbegin; p!=pend; ++p) {
    std::cout << ' ' << *p;
  }
  std::cout << '\n';
}

void removeIfVector() {
  vector<int> myints = {1,2,3,4,5,6,7,8,9,10};            // 1 2 3 4 5 6 7 8 9

  auto remove_fn = [&](int i) { 
    cout << "vector is now: " << myints << endl;
    return (i%2)==1;
  };
  auto delete_me = std::remove_if(myints.begin(), myints.end(), remove_fn);
  cout << "vector ended as: " << myints << endl;
  myints.erase(delete_me, myints.end());   // 2 4 6 8 ? ? ? ? ?
                                                 // ^       ^
  std::cout << "the range contains: " << myints << endl;
}

int main() {
  printf("hello world!\n");
  vector<int> values = {1, 2, 3, 4, 5};

  vector<vector<std::string>> letters = {{"abc", "def"}, {"ghi", "jkl"}};

  cout << "values:\n" << values << endl;

  cout << "letters:\n" << letters << endl;

  removeIfArray();
  removeIfVector();
  return 0;
}