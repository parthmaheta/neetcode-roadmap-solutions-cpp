#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start=0;
        int end=nums.size()-1;
        int answer=INT16_MAX;
        while (start<=end)
        {
            int mid=(start+end)/2;
            if(nums[start]<=nums[end]){
                return min(answer,nums[start]);
            }
            else if(nums[mid]>=nums[end]){
                  answer=min(nums[start],answer);
                  start=mid+1;
            }else{
                 answer=min(nums[mid],answer);
                 end=mid-1;   
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> v = {4, 5, 6, 7, 0, 1,2, 2,3,3};
    cout << s.findMin(v);
}