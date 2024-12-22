#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex; // Stores number and its index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // Find the complement
        // Check if complement exists in the map
        if (numToIndex.find(complement) != numToIndex.end()) {
            return {numToIndex[complement], i}; // Return indices of the two numbers
        }
        // Add the current number and its index to the map
        numToIndex[nums[i]] = i;
    }

    return {}; // Return empty if no solution is found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << "\n";
    } else {
        std::cout << "No solution found!\n";
    }

    return 0;
}
