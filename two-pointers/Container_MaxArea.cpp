#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;

        int start = 0;
        int end = height.size() - 1;
        while (start < end)
        {
            int area = min(height[start], height[end]) * (end - start);
            if (max < area)
                max = area;

            if (height[start] > height[end])
                end--;
            else
                start++;
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3, 4, 1, 2, 6, 8, 3, 1, 4};
    cout << s.maxArea(v);
}
