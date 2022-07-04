/*

Problem Statement:
Amazon's AWS provides fast and efficient server
solutions. The developers want to stress-test the
quality of the servers' channels. They must
ensure the following:
    • Each of the packets must be sent via a single
    channel.
    • Each of the channels must transfer at least one
    packet.

The quality of the transfer for a channel is
defined by the median of the sizes of all the data
packets sent through that channel.

Note: The median of an array is the middle
element if the array is sorted in non-decreasing
order. If the number of elements in the array is
even, the median is the average of the two
middle elements.

Find the maximum possible sum of the
qualities of all channels. If the answer is a
floating-point value, round it to the next higher
integer.
Example
packets = [1, 2, 3, 4, 5]
channels =2
At least one packet has to go through each of
the 2 channels. One maximal solution is to
transfer packets (1, 2, 3, 4} through channel 1
and packet (5} through channel 2.

The quality of transfer for channel 1 is (2 + 3)/2 =
2.5 and that of channel 2 is 5. Their sum is 2.5 +
5= 7.5 which rounds up to 8.

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