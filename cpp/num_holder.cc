// DO NOT COMPILE

#include <stdio.h>

class NumHolder {
 public:
  NumHolder() {
    vals = new int[10];
    for(int i = 0; i < 10; i++)
      vals[i] = i;
  }

  ~NumHolder() {
   delete vals;
  }

  void print() {
    for(int i = 0; i < 10; i++) {
      printf("%d ", vals[i]);
      vals[i]++;
    }
    printf("\n");
  }

 private:
  int *vals;
};

void func(NumHolder &foo) {
   NumHolder b = foo;
   b.print();
}

int main() {
  NumHolder a;
  a.print();
  func(a);
  a.print();
}

// DO NOT COMPILE
