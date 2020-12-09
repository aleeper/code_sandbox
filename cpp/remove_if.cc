#include "leeper_helpers.h"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>    // std::remove_if

using std::cout;
using std::endl;

void removeIfArray() {
  cout << "Running removeIfArray example:" << endl;
  int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

  // bounds of range:
  int* pbegin = myints;                          // ^
  int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

  auto remove_fn = [&](int i) { 
    cout << "vector is now: ";
    for (int* p=pbegin; p!=pend; ++p) {
      std::cout << ' ' << *p;
    }
    cout << endl;
    return (i%2)==1;
  };

  pend = std::remove_if(pbegin, pend, remove_fn);   // 2 4 6 8 ? ? ? ? ?
                                                 // ^       ^
  std::cout << "the range contains:";
  for (int* p=pbegin; p!=pend; ++p) {
    std::cout << ' ' << *p;
  }
  std::cout << '\n';
}

void removeIfVector() {
  cout << "Running removeIfVector example:" << endl;
  std::vector<int> myints = {1,2,3,4,5,6,7,8,9,10};            // 1 2 3 4 5 6 7 8 9

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
  removeIfArray();
  removeIfVector();
  return 0;
}