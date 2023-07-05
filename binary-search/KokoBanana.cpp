#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
   int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int max=findMax(piles);       
      
        while(start<=max){
            int mid=(start+max)/2;           

            if(calculateTime(piles,mid,h)){             
                 max=mid-1;                          
            }
            else
             start=mid+1;
        }
        return start;
        
    }
    int findMax(vector<int>& nums){
        int max=nums[0];
        for(int num:nums){
            if(max<num)
            max=num;
        }
        return max;
    }
    bool calculateTime(vector<int>& piles,int hourly,int maxTime){
     int answer=0;
     for(int pile:piles){
        answer+=ceil(pile/(double)hourly);
        if(answer>maxTime)
        return false;
     }
     return true;
    }
};

int main()
{
    Solution s;
    vector<int> v = {30,11,23,4,20};    
    cout << s.minEatingSpeed(v, 5);
}