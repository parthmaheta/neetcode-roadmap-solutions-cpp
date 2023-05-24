#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
       vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> output;
       
        
        int product=1;
        for(int index=0;index<nums.size();index++){
            product*=nums[index];
             output.push_back(product);
        }
        product=1;
        for(int index=nums.size()-1;index>0;index--){
            output[index]=output[index-1]*product;
            product*=nums[index];
        }
        output[0]=product;
       
        return output;
    }
};

void printVector(vector<int> v){
    cout<<"[";
    for(int i:v){
        cout<<i<<",";
    }
    cout<<"]\n";
}
int main(){
    Solution s;
    vector<int> v={1,2,3,4,5};  
    vector<int> ans =  s.productExceptSelf(v);
    printVector(ans);
}