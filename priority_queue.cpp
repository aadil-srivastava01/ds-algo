/*

Problem Link: Implement a Priority Queue(with impoved removal implementation
than prev commit)

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Pqueue {
 public:
  std::vector<int> q;
  int last_idx;
  Pqueue(int x) { q.push_back(x); }
  void moveup(int idx);
  void movedown(int idx);
  void remove(int idx);
  void insert(int idx);
  int extractmax();
  int peek() { return q[0]; }
  int left_child(int idx) { return idx * 2 + 1; }
  int right_child(int idx) { return idx * 2 + 2; }
  int parent(int idx) { return (idx - 1) / 2; }
  void update_last() { last_idx = q.size() - 1; }
  void traverse() {
    std::cout << "[ ";
    for (const auto &item : q) std::cout << item << " ";
    std::cout << " ]" << std::endl;
  }
};

void Pqueue::moveup(int idx) {
  int p = parent(idx);
  if (p > 0 && (q[idx] > q[p])) {
    std::swap(q[p], q[idx]);
    moveup(p);
  }
}

void Pqueue::movedown(int idx) {
  int left = left_child(idx);
  int right = right_child(idx);
  int maxI{0};

  if ((left <= last_idx) && (q[left] > q[idx])) {
    maxI = left;
  }
  if ((right <= last_idx) && (q[right] > q[idx])) {
    maxI = right;
  }
  if (maxI) {
    std::swap(q[idx], q[maxI]);
    movedown(maxI);
  }
  return;
}

void Pqueue::insert(int val) {
  q.push_back(val);
  update_last();
  moveup(q[last_idx]);
}

int Pqueue::extractmax() {
  int max = q[0];
  q[0] = q[last_idx];
  q.pop_back();
  movedown(0);
  update_last();
  return max;
}

void Pqueue::remove(int idx) {
  if (idx > last_idx) {
    std::cout << "Invalid Index\n";
    return;
  }
  q[idx] = q[0] + 1;
  moveup(idx);
  extractmax();
}

int main() {
  Pqueue pq{45};
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