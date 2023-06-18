#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    stack<pair<int, int>> stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stk.empty())
            stk.push(pair<int, int>(val, val));

        else if (stk.top().second > val)
            stk.push(pair<int, int>(val, val));
        else
            stk.push(pair<int, int>(val, stk.top().second));
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};

int main()
{

    MinStack *obj = new MinStack();
    obj->push(50);
    obj->push(30);
    obj->push(10);
    obj->push(110);
    obj->pop();
    cout<< obj->top();
    cout<<",";
    cout<< obj->getMin();

}