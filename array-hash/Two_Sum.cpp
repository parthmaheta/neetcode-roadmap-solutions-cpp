#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

void printVector(vector<int> v);

class Solution{
 public:


   vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> map;
    vector<int> answer;
    for(int index=0;index<nums.size();index++)  {
        int value= target- nums[index];
        unordered_map<int, int>::iterator it= map.find(value);
        if(it!=map.end()){
          answer= {it->second,index};
       
        }
        else
        map.insert(pair<int,int>(nums[index],index));
    }
    return answer;
   }

};

int main(){
    Solution s;
    vector<int> v1={2,7,11,15};
    vector<int> ans;
    ans=s.twoSum(v1,13);
    printVector(ans);
    
}

void printVector(vector<int> g){
    cout<<"[";
    for(int i:g){
        cout<<i<<" ,";
    }
    cout<<"]\n";
}