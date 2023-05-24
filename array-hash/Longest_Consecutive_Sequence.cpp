#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
  
  public:
  int longestConsecutive(vector<int>& nums){
      unordered_set<int> set;
      for(int i: nums){
        set.insert(i);
      }
      int max=0;
      
      for(int i:nums){
        int current=0;
        if(set.find(i-1)==set.end()){
            current++;
            int n=i+1;
            while(set.find(n)!=set.end()){
                current++;
                n++;
            }

          if(max<current){
            max=current;
          }  
        }
      }

      return max;
  }

};


int main(){
    Solution s;
   vector<int> v={0,3,7,2,5,8,4,6,0,1};
   cout<<s.longestConsecutive(v);
}