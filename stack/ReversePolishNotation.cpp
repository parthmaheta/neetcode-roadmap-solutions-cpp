#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {  
         stack<int> stk;
        for (string token:tokens)
        {
            if(token=="+"){
                int val1=stk.top();
                stk.pop();
                int val2=stk.top();
                stk.pop();
                stk.push(val2+val1);
            }
            else if(token=="-"){
                int val1=stk.top();
                stk.pop();
                int val2=stk.top();
                stk.pop();
                stk.push(val2-val1);
            }
            else if(token=="*"){
                int val1=stk.top();
                stk.pop();
                int val2=stk.top();
                stk.pop();
                stk.push(val2*val1);
            }
            else if(token=="/"){
                int val1=stk.top();
                stk.pop();
                int val2=stk.top();
                stk.pop();
                stk.push(val2/val1);
            }
            else{
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};

int main()
{
    Solution s;
    vector<string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(v);
};