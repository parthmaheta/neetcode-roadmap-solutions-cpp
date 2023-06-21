#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{

public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> stk;
        vector<int> answer(temperatures.size(),0);

        stk.push(pair<int, int>(temperatures[0], 0));
        for (int index = 1; index < temperatures.size(); index++)
        {
            if ((stk.empty())||stk.top().first >= temperatures[index])
            {
                stk.push(pair<int, int>(temperatures[index], index));
            }
            else
            {
               
                while((!stk.empty())&&temperatures[index]>stk.top().first)
                {
                 answer[stk.top().second]=index-stk.top().second;
                 stk.pop();
                }               

                stk.push(pair<int, int>(temperatures[index], index));
            }
        }
       
        return answer;
    }
};

void print(vector<int> v)
{
    for (int s : v)
    {
        cout << s << ",";
    }
}
int main()
{
    Solution s;
    vector<int> k = {30};
    vector<int> v = s.dailyTemperatures(k);
    print(v);
}