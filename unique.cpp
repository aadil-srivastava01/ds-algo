#include <iostream>
#include <vector>
#include <map>
#include <set>
class Solution
{
public:
    bool uniqueOccurrences(std::vector<int> &arr)
    {
        std::map<int, int> m1;
        std::vector<int> val;
        std::set<int> s1;
        for (int const &a : arr)
        {
            m1[a] += 1;
        }
        for (auto const &a : m1)
        {
            auto res = s1.insert(a.second);
            if (!res.second)
            {
                return false;
            };
        }
        return true;
    }
};

int main()
{
    Solution s1;
    std::vector<int> v1;
    v1 = {1, 2};
    std::cout << "Hello";
    std::cout << s1.uniqueOccurrences(v1) << std::endl;
    return 0;
}