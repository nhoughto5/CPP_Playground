#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class DynamicProgramming {
public:
    std::vector<int> howSum(int targetSum, const std::vector<int>& numbers)
    {
        if (targetSum == 0) return {};
        if (memMap.find(targetSum) != memMap.end()) return memMap[targetSum];

        for (auto n : numbers)
        {
            if (n <= targetSum)
            {
                memMap[targetSum - n] = howSum(targetSum - n, numbers);

                if (!std::binary_search(memMap[targetSum - n].begin(), memMap[targetSum - n].end(), -1))
                {
                    memMap[targetSum - n].push_back(n);
                    return memMap[targetSum - n];
                }
            }
        }

        return { -1 };
    }

private:
    std::map<int, std::vector<int>> memMap;
};