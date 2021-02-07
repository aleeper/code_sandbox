/*
You're building a tool to estimate the cost of various airplane tickets based on the airline, distance and seating class. Your tool must take in this information as a series of inputs (one ticket calculation per line of input) and produce a list of output costs.

Each airline contains its own cost requirements. Ultimately, the airline is only interested in two major components: the space you take on the plane, and the distance you fly. You must generate ticket costs using this gathered data:

Airlines: United, Delta, Southwest, LuigiAir

Operating Costs:

 - Economy:  No charge
 - Premium:  $25
 - Business: $50 + $0.25/mile

Per-Airline Prices:

 - Delta charges $0.50/mile
   + OperatingCost
   
 - United charges $0.75/mile
   + OperatingCost
   + $0.10/mile for Premium seats

 - Southwest charges $1.00/mile

 - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher

Keep in mind that, while there are only four airlines listed above, your solution should be able to expand to dozens of individual airlines,  whose ticket cost can be based on arbitrary functions of "Operating Costs", miles, and/or seating class.

You can assume that the input will be provided as a list of strings and that there could be millions of lines of input. Each string will provide the Airline, Distance and Seating Class. Please review the examples below:

Example Input:
-------------------------------------------
United 150.0 Premium
Delta 60.0 Business
Southwest 1000.0 Economy
LuigiAir 50.0 Business
-------------------------------------------

Example Output:
-------------------------------------------
152.50
95.00
1000.00
125.00
-------------------------------------------

Explanation of Output:
-------------------------------------------
152.50      (150.0 * (0.75 + 0.10) + 25)
95.00       (60.0 * (0.50 + 0.25) + 50)
1000.00     (1000.0 * 1.00)
125.00      (100 <= 2 * (50 + 50 * 0.25))
-------------------------------------------
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

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

struct RouteInfo {
  string airline;
  double miles;
  string seat_class;  // or enum class
};

std::ostream& operator<<(std::ostream& stream, const RouteInfo& info) {  
  stream << "[";
  stream << info.airline << ", " << info.miles << ", " << info.seat_class;
  stream << "]";
  return stream;
}

// copy so we can erase from it
RouteInfo parseRouteInfo(string route_string) {
  RouteInfo info;
  std::string delimiter = " ";

  size_t pos = 0;
  std::string token;
  int index = 0;
  while ((pos = route_string.find(delimiter)) != std::string::npos) {
    token = route_string.substr(0, pos);

    if (index == 0) {
       info.airline = token;
    } else if (index == 1) {
      info.miles = std::stod(token); 
    }
    index++;
    route_string.erase(0, pos + delimiter.length());
  }
   
  info.seat_class = route_string;
  
  return info;
}

class Calculator {

  unordered_map<string, std::function<double(RouteInfo)> > cost_functions_;

//   Operating Costs:

//  - Economy:  No charge
//  - Premium:  $25
//  - Business: $50 + $0.25/mile

// Per-Airline Prices:

//  - Delta charges $0.50/mile
//    + OperatingCost
   
//  - United charges $0.75/mile
//    + OperatingCost
//    + $0.10/mile for Premium seats

//  - Southwest charges $1.00/mile

//  - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher
  static double getOperatingCost(double miles, const string& seat_class) {
    if (seat_class == "Premium") {
      return 25.0;
    } else if (seat_class == "Business") {
      return 50.0 + 0.25 * miles; 
    }
    return 0.0;
  }

 public:
  Calculator() {
    cost_functions_["United"] = [](RouteInfo info) {
      double mileage_cost = 0.75 * info.miles;
      if (info.seat_class == "Premium") {
        mileage_cost += 0.1 * info.miles;
      }
      double operating_cost = getOperatingCost(info.miles, info.seat_class);
      return mileage_cost + operating_cost;
    };
    cost_functions_["Delta"] = [](RouteInfo info) {
      double mileage_cost = 0.50 * info.miles;
      double operating_cost = getOperatingCost(info.miles, info.seat_class);
      return mileage_cost + operating_cost;
    };
    cost_functions_["Southwest"] = [](RouteInfo info) {
      double mileage_cost = 1.0 * info.miles;
      double operating_cost = 0.0;
      return mileage_cost + operating_cost;
    };
    cost_functions_["LuigiAir"] = [](RouteInfo info) {
      double operating_cost = getOperatingCost(info.miles, info.seat_class);
      return std::max(100.0, 2.0 * operating_cost);
    };
     
  }
  
  // Could be a AirlineCostInterface* 
  void addAirline() { // take in airline name and cost function
    
    
  }
  
  vector<double> getCosts(const vector<string>& input) {

    vector<double> result;
    for (const string& line : input) {
      RouteInfo info = parseRouteInfo(line);
      cout << "info: " << info << endl;
      // Assume that we will only see airlines we know about.
      double cost = cost_functions_[info.airline](info);
      result.push_back(cost);
    }

    return result;
  }
  
};


int main() {
  const vector<string> input = {
      "United 150.0 Premium",
      "Delta 60.0 Business",
      "Southwest 1000.0 Economy",
      "LuigiAir 50.0 Business"
    };
  
// 152.50
// 95.00
// 1000.00
// 125.00
  
  Calculator c;
  vector<double> costs = c.getCosts(input);
  
  cout << "input:\n" << input << endl;
  cout << "costs:\n" << costs << endl;
  
  return 0;
}