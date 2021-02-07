

struct Node {
  int value;
  Node* next;
}


A -> B -> C

Node* reverseList(Node* head) {
  Node* previous = nullptr;
  Node* current = head;
  while (current) {
    Node* next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  return previous; 
}



[5, 7, 4, 3, 6, 7]
maximize profit


int maxProfit(const std::vector<int>& prices) {
  // error handling
  
  int max_profit = 0;
  int min_so_far = prices[0];
  for (int price : prices) {
    if (price >= min_so_far) {
      int delta = price - min_so_far;
      if (delta > max_profit) {
        max_profit = delta;
      }
    } else {
      min_so_far = price;
    }
  }
  
  return max_profit;
}


// multiple machines
// how to partition the data
// what to compute per machine
// write algo consume the per-machine results to get globally correct algo.

struct Month {
  int min;
  int max;
  int max_profit;
}

int maxProfit(const std::vector<Month>& months) {
  int biggest_profit = months[0].max_profit;
  
  int min_so_far = months[0].min;
  for (const Month& month : months) {
    
    int delta = month.max - min_so_far;
    
    biggest_profit = std::max(biggest_profit, delta);
    biggest_profit = std::max(biggest_profit, month.max_profit);
    
    if (month.min < min_so_far) {
      min_so_far = month.min;
    }
  }
  
  return biggest_profit;
}


[[2, 1, 3],
 [6, 5, 4],
 [8, 7, 9]]
 
// Cheapest path from anywhere on top to anywhere on bottom.



// #include <iostream>
// using namespace std;

// // To execute C++, please define "int main()"
// int main() {
//   auto words = { "Hello, ", "World!", "\n" };
//   for (const string& word : words) {
//     cout << word;
//   }
//   return 0;
// }
