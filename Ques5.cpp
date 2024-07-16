// 5. Write a function to rotate an array to the right by k steps.The function should modify the array in place to achieve the rotation.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums, 3);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl; // Output: 5 6 7 1 2 3 4
    return 0;
}
