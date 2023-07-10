#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        int ans = 0;
        vector<int> vec(26, 0);
        int left = 0;
        int mxChar=0;
        for (int index = 0; index < s.size(); index++)
        {
            
            vec[int(s[index]) - 65]++;
            mxChar=max(mxChar,vec[int(s[index])-65]);
            if ((index - left + 1) - mxChar > k)
            {
                vec[int(s[left]) - 65]--;
                left++;
            }
            ans = max(index - left + 1, ans);
        }
        return ans;
    }   
};

int main()
{
    Solution s;
    cout << s.characterReplacement("AABABBAAB",3);
}