// num_valid_subarrays.cpp
#include "num_valid_subarrays.hpp"
#include <vector>
#include <stack>

int numValidSubarrays(const std::vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return 1;
    }

    // Initlialized to 'n' to make calculations easier if any element does not have a next smaller index until the end of the array
    std::vector<int> nextSmaller(n, n);
    // Monotonic increasing stack to help find the next smaller index for each nums[i], if is such element
    std::stack<int, std::vector<int>> monotonicIncreasing;
    for (int i = 0; i < n; i++)
    {
        // While the stack is non-empty and the top of the stack element is greater than the current element
        while (!monotonicIncreasing.empty() && nums[monotonicIncreasing.top()] > nums[i])
        {
            // We have found the smaller next index for nums[monotonicIncreasing.top()], pop the top and update the nextSmaller array
            nextSmaller[monotonicIncreasing.top()] = i;
            monotonicIncreasing.pop();
        }
        // Push the index to the stack
        monotonicIncreasing.push(i);
    }

    // Sum all counts of valid subarray
    int validSubarrayCount = 0;
    for (int i = 0; i < n; i++)
    {
        validSubarrayCount += nextSmaller[i] - i;
    }

    return validSubarrayCount;
}
