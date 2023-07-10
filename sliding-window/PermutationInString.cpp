#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        int match = 0;
     
        for (int index = 0; index < s1.size(); index++)
        {
            map1[int(s1[index]) - 97]++;
            map2[int(s2[index]) - 97]++;
        }

        for (int index=0;index<26;index++)
        {
            if (map1[index] == map2[index])
                match++;
        }

        if (match == 26)
            return true;

        int left = 0;
        for (int index = s1.size(); index < s2.size(); index++)
        {
            map2[int(s2[left]) - 97]--;
            if (map1[int(s2[left]) - 97] == map2[int(s2[left]) - 97])
                match++;
            else if (map1[int(s2[left]) - 97] == map2[int(s2[left]) - 97] + 1)
            {
                match--;
            }

            left++;
            map2[int(s2[index]) - 97]++;

            if (map1[int(s2[index]) - 97] == map2[int(s2[index]) - 97])
                match++;
            else if (map1[int(s2[index]) - 97] == map2[int(s2[index]) - 97] - 1)
            {
                match--;
            }

            if (match == 26)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution s;
    cout << s.checkInclusion("ab", "eidboaoo");
}