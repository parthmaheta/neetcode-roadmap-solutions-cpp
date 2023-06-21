#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> cars;
        for (int index=0;index<position.size();index++)
        {
            cars.push_back(pair<int, int>(position[index], speed[index]));
        }
        sort(cars.begin(), cars.end());
              
        int answer = 0;
        float lastCarTime = (target - cars[cars.size() - 1].first) /(float) cars[cars.size() - 1].second;
        for (int index = cars.size() - 2; index >= 0; index--)
        {   
            float currentCarTime = (target - cars[index].first) / (float)cars[index].second;
            
            if (lastCarTime < currentCarTime)
            {
                answer++;
                lastCarTime = (target - cars[index].first) /(float) cars[index].second;
            }
            
        }
        answer++;
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> pos = {6,8};
    vector<int> speed = {3,2};
    cout << s.carFleet(10, pos, speed);
}