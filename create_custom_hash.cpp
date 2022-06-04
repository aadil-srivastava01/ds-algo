/*

Problem Link: Creating Custom HashTable

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class CustomHashmap {
 private:
  int size;
  int hash_size;
  std::pair<std::string, int> *ptr{nullptr};
  int *fill_idx_ptr{nullptr};

 public:
  CustomHashmap(int hash_space);
  ~CustomHashmap() { delete[] ptr; }
  int _hash(const std::string &key) const;
  auto get(const std::string &key) const;
  void set(const std::string &key, int value);
  void keys() const;
};

CustomHashmap::CustomHashmap(int hash_space) : size{hash_space}, hash_size{0} {
  ptr = new std::pair<std::string, int>[size];
  fill_idx_ptr = new int[size];
}

int CustomHashmap::_hash(const std::string &key) const {
  int hash{0};
  size_t key_size{key.size()};
  for (size_t i = 0; i < key_size; i++) {
    hash = (hash + (int)key.at(i) * i) % size;
  }
  return hash;
}

auto CustomHashmap::get(const std::string &key) const {
  int idx = _hash(key);
  return *(ptr + idx);
}

void CustomHashmap::set(const std::string &key, int value) {
  int idx = _hash(key);
  ptr[idx] = std::pair<std::string, int>{key, value};
  fill_idx_ptr[hash_size] = idx;
  hash_size++;
}

void CustomHashmap::keys() const {
  for (int i = 0; i < hash_size; i++) {
    std::cout << (ptr + fill_idx_ptr[i])->first << ": ";
    std::cout << (ptr + fill_idx_ptr[i])->second << "\n";
  }
  std::cout << std::endl;
}
int main() {
  CustomHashmap h1{50};
  h1.set("grapes", 1000);
  h1.set("Orages", 11);
  h1.set("apple", 15);
  h1.keys();
  std::cout << std::endl;
  return 0;
}