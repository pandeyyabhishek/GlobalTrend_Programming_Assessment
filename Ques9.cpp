// 9. Write a function to find the maximum difference between any two elements in an array.The //function should return the maximum difference between any two elements in the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDifference(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int minElement = nums[0];
    int maxDiff = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        maxDiff = max(maxDiff, nums[i] - minElement);
        minElement = min(minElement, nums[i]);
    }
    return maxDiff;
}

int main()
{
    vector<int> nums = {2, 3, 10, 2, 4, 8, 1};
    cout << maxDifference(nums) << endl; // Output: 8
    return 0;
}
