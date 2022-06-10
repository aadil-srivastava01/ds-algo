/*

Problem Link: Building a simple graph

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Graph {
 private:
  std::unordered_map<std::string, std::vector<std::string>> adjacent_list;

 public:
  void add_vertex(std::string val);
  void add_edge(std::string node1, std::string node2);
  void showConeections();
};

void Graph::add_vertex(std::string val) {
  std::vector<std::string> edge;
  adjacent_list.emplace(std::make_pair(val, edge));
}

void Graph::add_edge(std::string vertex1, std::string vertex2) {
  adjacent_list.at(vertex1).push_back(vertex2);
  adjacent_list.at(vertex2).push_back(vertex1);
}
void Graph::showConeections() {
  auto it = adjacent_list.begin();
  while (it != adjacent_list.end()) {
    std::cout << it->first << "-->";
    for (const auto &item : it->second) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
    it++;
  }
}

int main() {
  Graph g1;
  g1.add_vertex("0");
  g1.add_vertex("1");
  g1.add_vertex("2");
  g1.add_vertex("3");
  g1.add_vertex("4");
  g1.add_vertex("5");
  g1.add_vertex("6");

  g1.add_edge("3", "1");
  g1.add_edge("3", "4");
  g1.add_edge("4", "2");
  g1.add_edge("4", "5");
  g1.add_edge("1", "2");
  g1.add_edge("1", "0");
  g1.add_edge("0", "2");
  g1.add_edge("6", "5");

  g1.showConeections();

  std::cout << std::endl;
  return 0;
}