#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<pair<int, int>> stk;
        for (int index = 0; index < heights.size(); index++)
        {
            int start = index;
            while ((!stk.empty()) && (stk.top().second > heights[index]))
            {
                start = stk.top().first;
                maxArea = max(maxArea, stk.top().second * (index - start));
                stk.pop();
            }
            stk.push(pair<int, int>(start, heights[index]));
        }
        while (!stk.empty())
        {
            int max = stk.top().second * (heights.size() - stk.top().first);
            if (maxArea < max)
            {
                maxArea = max;
            }

            stk.pop();
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 1,2, 5, 6, 2, 3};
    cout << s.largestRectangleArea(v);
}