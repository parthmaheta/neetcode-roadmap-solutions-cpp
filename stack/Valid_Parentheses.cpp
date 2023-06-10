#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c:s)
        { 
            
            if(c=='}'&&((stack.size()==0)||stack.top()!='{')){
                return false;
            }
            else if(c==']'&&((stack.size()==0)||stack.top()!='[')){
                return false;
            }
            else if(c==')'&&((stack.size()==0)||(stack.top()!='('))){
                return false;
            }
            else if(c=='{'||c=='['||c=='('){
                stack.push(c);
            }
            else if(stack.size()>0){
                stack.pop();
            }

        }
       return  stack.empty();
         
        
    }
};


int main(){
    Solution s;
    cout<<s.isValid("()")<<"\n";
    cout<<s.isValid("()[]{}")<<"\n";
    cout<<s.isValid("]")<<"\n";


}