#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
        {
            return {};
        }
        if (nums[0] > 0)
        {
            return {};
        }
        vector<vector<int>> ans;
        for (int index = 0; index < nums.size() - 2; index++)
        {

            int start = index + 1;
            int end = nums.size() - 1;
            if ((index != 0) && (nums[index] == nums[index - 1]))
                continue;
            while (start < end)
            {

                if (nums[index] + nums[start] + nums[end] > 0)
                    end--;
                else if (nums[index] + nums[start] + nums[end] < 0)
                    start++;
                else
                {
                    ans.push_back({nums[index], nums[start], nums[end]});

                    while ((end > start) && (nums[start] == nums[start + 1]))
                        start++;
                    while ((end > start) && (nums[end] == nums[end - 1]))
                        end--;

                    start++;
                    end--;
                }
            }
        }
        return ans;
    }
};

void printVector(vector<vector<int>> nums)
{
    for (vector<int> vals : nums)
    {
        for (int val : vals)
        {
            cout << "," << val;
        }
        cout << "\n";
    }
}

int main()
{
    Solution s;
    vector<int> v = {1, 2, -2, -1};
    vector<vector<int>> ans = s.threeSum(v);
    printVector(ans);
}