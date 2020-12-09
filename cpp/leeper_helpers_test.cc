#include "leeper_helpers.h"

#include <map>
#include <vector>


int main() {
  using std::cout;
  using std::endl;
  using std::vector;

  vector<int> one_dim = {1, 2, 3, 4, 5};

  vector<vector<std::string>> two_dim = {{"abc", "def"}, {"ghi", "jkl"}};

  cout << "one_dim ints: " << one_dim << endl;
  cout << "one_dim strings: " << two_dim[0] << endl;

  cout << "two_dim strings:\n" << two_dim << endl;


  std::map<std::string, int> my_map = {{"adam", 17}, {"john", 23}, {"mary", 15}};
  cout << my_map << endl;

  return 0;
}