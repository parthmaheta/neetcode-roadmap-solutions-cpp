#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (int i : nums)
        {
            umap[i] += 1;
        }

        vector<int> freq[nums.size()+1];

        for(auto val:umap){
              freq[val.second].push_back(val.first);      
        }
        int index=0;
        vector<int> ans;
        for (int i = nums.size(); i > 0; i--)
        {
              if (freq[i].size() > 0)
              {
                  for (auto it : freq[i])
                  {
                      if(index<k)   
                      {ans.push_back(it);
                       index++;
                      }
                      else{
                        return ans;
                      }
                  }

              }
        }
        return ans;
    }
};

void printVector(vector<int>);

int main()
{
    Solution s;
    vector<int> v = {1,1,1,2,2,3};
    vector<int> ans = s.topKFrequent(v, 2);
    printVector(ans);
}

void printVector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << ",";
    }
    cout << "\n";
}