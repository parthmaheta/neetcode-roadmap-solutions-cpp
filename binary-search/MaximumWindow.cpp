#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        vector<int> output;
        list<int> deque;

        while (right < nums.size())
        {
            while (deque.size() > 0 && nums[deque.back()] <= nums[right])
            {
                deque.pop_back();
            }
            deque.push_back(right);
            if (left > deque.front())
                deque.pop_front();

            if (right + 1 >= k)
            {
                output.push_back(nums[deque.front()]);
                left++;
            }

            right++;
        }
        return output;
    }
};

void print(vector<int> nums)
{
    for (int n : nums)
    {
        cout << n << " ";
    }
}

int main()
{
    Solution s;
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    print(s.maxSlidingWindow(v, 3));
}