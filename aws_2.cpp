/*

Problem Link:
Amazon Web Services (AWS) has several data
centers which have multiple processors that
perform computations. In one such data center,
these processors are placed in a sequence with
their IDs denoted by 1, 2, ., n. Each processor
consumes a certain amount of power to boot
up, denoted by bootingPower[]. After booting, a
processor uses processingPowerli] of power to
run the processes. For maximum utilization, the
data center wishes to group these processors
into clusters. Clusters&can only be formed of
processors located adjacent to each other. For
example, processors 2, 3, 4, 5 can form a
cluster, but 1, 3, 4 cannot.

The net power consumption of a cluster of k
processors (i, i + 1, .., i + k - 1) is defined as:

is, net power consumption = maximum
booting power among the k processors + (sum
of processing power of processors) * k.

given the booting power consumption and the
Processing power consumption of n processors
denoted by bootingPower and processingPower
respectively, and the threshold value powerMax,
find the maximum possible number of
processors which can be grouped together to
form a sustainable cluster. If no such clusters
can be formed, return 0.
Note: It is not mandatory for all clusters of size
kto be sustainable. Even one such cluster is
sufficient.
Example
bootingPower = [3, 6, 1, 3, 4]
processingPower = [2, 1, 3, 4, 5]
powerMax = 25
If k= 2, any adjacent pair can be chosen. The
highest usage is the pair [4, 5] with net power
consumption 4 + (4 + 5) * 2 = 22. Next, try K = 3.
Group the first 3 processors together as:

If k= 2, any adjacent pair can be chosen. The
highest usage is the pair [4, 5] with net power
consumption 4 + (4 + 5) * 2 = 22. Next, try K = 3.

Here,
• Maximum booting power = max(3, 6, 1) = 6
• Sum of processing powers = 2 + 1 + 3 = 6
• Thus, net power consumption = 6 + 6 * 3 = 24 <=
powerMax

Thus, we can group k= 3 processors to form a
sustainable cluster. Note that the minimum
power consumption to form a cluster ofk = 4
processors is 46, by forming a cluster of the first
4 processors. Since this cost is greater than the
threshold, we cannot form a cluster with 4
processors. The maximum possible cluster size
is 3.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maximumsustainableclustersize(std::vector<int> &boot_power,
                                  std::vector<int> &processing_power,
                                  int powerthreshold) {
  int i{0}, j{0}, global_cluster_size{0}, local_cluster_size{0};
  int size = boot_power.size();
  int local_boot_max{0};
  int local_power_max{INT_MAX};
  int sum{0};
  while (i < size) {
    sum = 0;
    local_boot_max = boot_power.at(i);
    for (j = i; j < size; j++) {
      if (boot_power.at(j) > local_boot_max) local_boot_max = boot_power.at(j);
      sum += processing_power.at(j);
      local_cluster_size = j - i + 1;
      local_power_max = local_boot_max + sum * (local_cluster_size);
      if (local_power_max <= powerthreshold) {
        if (global_cluster_size < local_cluster_size)
          global_cluster_size = local_cluster_size;
      }
    }
    i++;
  }
  return global_cluster_size;
}

int main() {
  std::vector<int> v1{3, 6, 1, 3, 4};
  std::vector<int> v2{2, 1, 3, 4, 5};
  std::cout << maximumsustainableclustersize(v1, v2, 25);
  std::cout << std::endl;
  return 0;
}