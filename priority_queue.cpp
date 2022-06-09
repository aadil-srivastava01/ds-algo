/*

Problem Link: Implement a Priority Queue

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class PQueue {
 private:
  int last_idx;
  int parent_idx;
  int tmp;
  void fix_property(int pidx, int cidx);

 public:
  std::vector<int> q;
  PQueue(int x);
  void insert(int x);
  int extractMax();
  void remove(int idx);
  int getMax();
  void traverse();
};

PQueue::PQueue(int x) {
  q.emplace_back(x);
  last_idx = 0;
}
void PQueue::insert(int x) {
  q.emplace_back(x);
  last_idx++;
  parent_idx = (last_idx - 1) / 2;
  fix_property(parent_idx, last_idx);
};

void PQueue::fix_property(int pidx, int cidx) {
  if (pidx < 0) return;
  if (q.at(pidx) < q.at(cidx)) {
    std::swap(q.at(pidx), q.at(cidx));
    cidx = pidx;
    pidx = (pidx - 1) / 2;
    fix_property(pidx, cidx);
  }
}

void PQueue::remove(int idx) {
  int size = q.size();
  int tmp_parent;
  if (idx >= size) {
    std::cout << "Invalid Index\n";
    return;
  } else {
    for (int i = idx; i < size - 1; i++) {
      q.at(i) = q.at(i + 1);
    }
    q.pop_back();
    size = q.size();
    for (int i = size - 1; i > 0; i--) {
      tmp_parent = (i - 1) / 2;
      if (q.at(i) > q.at(tmp_parent)) std::swap(q.at(tmp_parent), q.at(i));
    }
  }
}

int PQueue::extractMax() {
  int tmp = q.at(0);
  remove(0);
}

void PQueue::traverse() {
  std::cout << "[ ";
  for (const auto &item : q) std::cout << item << " ";
  std::cout << " ]" << std::endl;
}

int main() {
  PQueue pq{45};
  pq.insert(31);
  pq.insert(20);
  pq.insert(14);
  pq.insert(7);
  pq.insert(12);
  pq.insert(19);
  pq.insert(32);
  pq.traverse();
  pq.remove(1);
  pq.traverse();
  std::cout << std::endl;
  return 0;
}