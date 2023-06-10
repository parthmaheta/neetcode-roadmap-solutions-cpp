#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v)
{
    // Printing all the elements
    // using <<
    for (auto element : v)
    {
        cout << element << " ";
    }
}

class Solution
{
public:
    int trap(vector<int> &height)
    {

        if (height.size() < 3)
            return 0;
        int left = 1;
        int right = height.size() - 2;
        int lmax = height[0];
        int rmax = height[height.size() - 1];
        int capacity = 0;
        while (left <= right)
        {
            if (lmax < height[left])
            {
                lmax = height[left];
                left++;
            }
            else if (rmax < height[right])
            {
                rmax = height[right];
                right--;
            }
            else if (lmax < rmax)
            {
                capacity += lmax - height[left];
                left++;
            }
            else
            {
                capacity += rmax - height[right];
                right--;
            }
        }

        return capacity;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(v);
}