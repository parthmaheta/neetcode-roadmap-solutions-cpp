#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto it: nums){
            if(set.find(it)==set.end()){
                set.insert(it);            
            }else{
                return true;
            }
            
        }
        return false;
    }
  

};

int main(){
    Solution s;
    vector<int> v1={1,2,3,4};
    vector<int> v2={1,2,1,4};
    vector<int> v3={1,1,1,3,3,4,3,2,4,2};
    vector<int> v4={1,11,111,13,31,4,3,21,14,2};
    cout<<s.containsDuplicate(v1)<<" {1,2,3,4} \n";
    cout<<s.containsDuplicate(v2)<<" {1,2,1,4} \n";
    cout<<s.containsDuplicate(v3)<<" {} \n";
    cout<<s.containsDuplicate(v4)<<" {} \n";
}