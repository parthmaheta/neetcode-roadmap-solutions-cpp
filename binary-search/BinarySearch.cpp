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
            int mid = (end + start) / 2;
            if (nums[mid] == target)
                return mid;       
            else if (nums[mid] > target)
                end = mid-1;
            else if(nums[mid]<target)
                start = mid+1;
        }
        return -1;
    }
};


int main()
{
    Solution s;
    vector<int> v = {-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(v, target);
}