#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 0;
        unordered_set<char> set;
        int left = 0;
        for (int index = 0; index < s.size(); index++)
        {

            while (set.find(s[index]) != set.end())
            {
                if (max < set.size())
                    max = set.size();
                set.erase(s[left]);
                left++;
            }
            set.insert(s[index]);
        }
        return max >= set.size() ? max : set.size();
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("bbbbb");
}