#include "leeper_helpers.h"

#include <vector>


int main() {
  using std::cout;
  using std::endl;
  using std::vector;

  vector<int> one_dim = {1, 2, 3, 4, 5};

  vector<vector<std::string>> two_dim = {{"abc", "def"}, {"ghi", "jkl"}};

  cout << "one_dim ints:\n" << one_dim << endl;
  cout << "one_dim strings:\n" << two_dim[0] << endl;

  cout << "two_dim strings:\n" << two_dim << endl;

  return 0;
}