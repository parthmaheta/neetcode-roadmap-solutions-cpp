#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size()||t=="")
            return "";

        unordered_map<char, int> mapT;
        unordered_map<char, int> mapS;

        for (int index = 0; index < t.size(); index++)
        {
            mapT[t[index]]++;
        }
        int have = 0;
        int need = 0;
        for (auto it : mapT)
        {
            need++;
        }

        int left = 0;
        int start = 0;
        int chars = 0;
        for (int index = 0; index < s.size(); index++)
        {

            if (mapT.count(s[index]) == 1)
            {
                mapS[s[index]]++;

                if (mapS[s[index]] == mapT[s[index]])
                    have++;

                if (have == need && ((chars > index - left + 1) || chars == 0))
                {
                    start = left;
                    chars = index - left + 1;
                }
            }
            while (have == need)
            {
                if (mapS.count(s[left]) == 1)
                {

                    mapS[s[left]]--;
                    if (mapS[s[left]] + 1 == mapT[s[left]])
                        have--;
                }

                left++;

                if (have == need && ((chars > index - left + 1) || chars == 0))
                {
                    start = left;
                    chars = index - left + 1;
                }
            }
        }

        return chars == 0 ? "" : s.substr(start, chars);
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("DCVBA", "ABC");
}