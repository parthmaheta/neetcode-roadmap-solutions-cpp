#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    
    void generateSolution(int open,int close,string ans,int max,vector<string>& answer){
        if(ans.size()==max*2){
            answer.push_back(ans);
            return;
        }
        if(open<max){
           generateSolution(open+1,close,ans+"(",max,answer);
        }
        if(close<open){
           generateSolution(open,close+1,ans+")",max,answer);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        generateSolution(0,0,"",n,answer);
        return answer;
    }
};

void print(vector<string> v){
    for(string s:v){
        cout<<s<<",";
    }
}
int main(){
  Solution s;
  vector<string> v=s.generateParenthesis(2);
  print(v);

}