#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
    vector<int> towSum(vector<int>& numbers,int target){
        int start=0,end=numbers.size()-1;
          while(start<end){
             if(target==numbers[start]+numbers[end])
                return {start+1,end+1};             
             else if(target>numbers[start]+numbers[end])
              start++;
             else
              end--; 
          }  
          return {-1,-1};
    }
};

void printVector(vector<int> v){
    cout<<"[ ";
    for(auto i:v){
        cout<<i<<",";
    }
    cout<<"]";
}

int main(){
    Solution s;
    vector<int> v={0,2,7,11,15};
    vector<int> j=s.towSum(v,9);
    printVector(j);
     

}