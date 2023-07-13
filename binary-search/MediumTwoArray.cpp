#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int total=nums1.size()+nums2.size();
        int half=(total/2);

        int start=0;
        int end=nums1.size()-1;
       
        while(true){
            int mid=(int) floor((start+end)/2.0);

            int left1=mid<0?INT32_MIN:nums1[mid];
            int left2=mid+1>=nums1.size()?INT32_MAX:nums1[mid+1];
                        
            int right1=half-(mid+1)-1<0?INT32_MIN:nums2[half-mid-2];
            int right2=half-(mid+1)>=nums2.size()?INT32_MAX:nums2[half-mid-1];

            if(left1<=right2&&right1<=left2)
            {
                if (total % 2 == 0)
                {
                    return (max(left1,right1)+min(left2, right2))/2.0;
                }
                else
                {
                    return min(left2, right2);
                }
            }
            else if(left1>right2){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }                       

       
        return 0.0;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1000};
    vector<int> v2 = {1001};
    cout << s.findMedianSortedArrays(v1,v2);
}

// {1,2,3,4,5}
// {1,2,3,4,5,6,7}
// {1,1,2,2,3,3,4,4,5,5,6,7}

