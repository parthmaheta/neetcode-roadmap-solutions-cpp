#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if ((nums[start] <= nums[mid] && target >= nums[start] && target <= nums[mid]) || (nums[mid] <= nums[end] && (target > nums[end] || target < nums[mid])))
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {5, 1, 3};
    cout << s.search(v, 5);
}