#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int minimum = prices[0];
        for (int price : prices)
        {   
            if (maxProfit < price - minimum)
                maxProfit = price - minimum;
             minimum = min(price, minimum);
        }
        return maxProfit;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {10,1,9,4,21};
    cout << s.maxProfit(vec);
}