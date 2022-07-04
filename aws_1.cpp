/*

Problem Link: Find the maximum possible sum of Qualities all channels

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

long maximumQuality(std::vector<int> packets, int channel) {
  int packet_size = packets.size();
  float sum{0};
  if (packet_size == channel) {
    for (int &item : packets) sum += item;
    return static_cast<long>(sum);
  }

  std::sort(packets.begin(), packets.end());
  int last_idx = packet_size - channel;
  for (int i = last_idx + 1; i < packet_size; i++) sum += packets.at(i);
  float tmp{0};
  if ((last_idx + 1) % 2 == 0) {
    tmp = packets[last_idx / 2] + packets[last_idx / 2 + 1];
    tmp = tmp / 2;
  } else
    tmp = packets[last_idx / 2];
  return static_cast<long>(std::ceil(tmp + sum));
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  std::cout << maximumQuality(v, 2);
  std::cout << std::endl;
  return 0;
}