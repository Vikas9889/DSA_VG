#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Sort the array to make it easier to find unique triplets
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first number
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                // Found a triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for the second number
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // Skip duplicates for the third number
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> triplets = threeSum(nums);

    cout << "Unique triplets that sum to 0 are:" << endl;
    for (auto& triplet : triplets) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
