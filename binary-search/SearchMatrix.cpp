#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int first = 0;
        int last = matrix.size() - 1;
        while (first <= last)
        {
            int mid = (first + last) / 2;
            if (target < matrix[mid][0])
                last = mid - 1;
            else if (target > matrix[mid][matrix[mid].size() - 1])
                first = mid + 1;
            else
                return binarySearch(matrix[mid], target);
        }
        return false;
    }
    bool binarySearch(vector<int> &nums, int target)
    {
        int first = 0;
        int last = nums.size() - 1;
        while (first <= last)
        {
            int mid = (first + last) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                last = mid - 1;
            else
                first = mid + 1;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << s.searchMatrix(v, target);
}