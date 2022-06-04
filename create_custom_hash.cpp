/*

Problem Link: Creating Custom HashTable

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class CustomHashmap {
 private:
  int size;
  int *p{nullptr};

 public:
  int _hash(const std::string &key) const;
  CustomHashmap(int hash_space);
  ~CustomHashmap() { delete[] p; }
  int get(const std::string &key);
  void set(const std::string &key, int value);
};

int CustomHashmap::_hash(const std::string &key) const {
  int hash{0};
  size_t key_size{key.size()};
  for (size_t i = 0; i < key_size; i++) {
    hash = (hash + (int)key.at(i) * i) % size;
  }
  return hash;
}
CustomHashmap::CustomHashmap(int hash_space) : size{hash_space} {
  p = new int[size];
}

int CustomHashmap::get(const std::string &key) {
  int idx = _hash(key);
  return *(p + idx);
}
void CustomHashmap::set(const std::string &key, int value) {
  int idx = _hash(key);
  *(p + idx) = value;
}

int main() {
    CustomHashmap h1{50};
    std::cout << h1._hash("grapess");
//   std::string s1{"aadil"};
//   std::cout << (int)s1.at(2);
  std::cout << std::endl;
  return 0;
}