// 2. Given a string, find the length of the longest substring without repeating characters.The function should return an integer representing the length of the longest substring without repeating characters.

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        int left = 0, right = 0, maxLength = 0;
        while (right < s.length())
        {
            if (set.find(s[right]) == set.end())
            {
                set.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
            else
            {
                set.erase(s[left]);
                left++;
            }
        }
        return maxLength;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl; // Output: 3
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;    // Output: 1
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;   // Output: 3
    return 0;
}
