#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

struct Vertex {
  float x;
  float y;
  float z;

  bool operator==(const Vertex& rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z;
  }
};

struct MyHash {
  size_t operator ()(const Vertex& v) const {
    std::stringstream ss;
    ss << v.x << "," << v.y << "," << v.z; 
    return hash<string>{}(ss.str());
  }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& v) {  
  stream << "[";
  stream << v.x << ", " << v.y << ", " << v.z;
  stream << "]";
  return stream;
}

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

void deduplicateVertices(const std::vector<Vertex>& input,
                         std::vector<Vertex>& vertices,
                         std::vector<int>& indices) {
  vertices.clear();
  indices.clear();
  indices.reserve(input.size());
  
  unordered_map<Vertex, int, MyHash> unique_vertices;
  for (const Vertex& v : input) {
    
    auto iter = unique_vertices.find(v);
    if (iter == unique_vertices.end()) { // doesn't exist
      unique_vertices.insert(std::make_pair(v, unique_vertices.size()));
      vertices.push_back(v);
    }
    indices.push_back(unique_vertices[v]);
  }
  
}


// To execute C++, please define "int main()"
int main() {
  
  vector<Vertex> v = {
    Vertex{0, 0, 0},
    Vertex{0, 0, 1},
    Vertex{0, 1, 0},
    Vertex{0, 0, 1},
    Vertex{0, 1, 0},
    Vertex{0, 1, 1}
  };
  
  cout << "input: " << v << endl;
  vector<Vertex> vertices;
  vector<int> indices;
  deduplicateVertices(v, vertices, indices);
  cout << "vertices: " << vertices << endl;
  cout << "indices: " << indices << endl;
  
  return 0;
}
