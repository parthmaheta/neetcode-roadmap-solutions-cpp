#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> umap;
        for (string s : strs)
        {
            int arr[26]={0};
            for(char ch:s){
                arr[int(ch)-int('a')]++;
            }
           
            string key;
           
             for(int i=0;i<26;i++){
              key.append(arr[i],i+'a');
        }
            
            umap[key].push_back(s);
          
           
        }
        vector<vector<string>> answer;
        for (auto it : umap)
        {
            answer.push_back(it.second);
        }
        return answer;
    }
    

};

void printVector(vector<vector<string>> &v)
{
    for (auto it : v)
    {
        cout << " [";
        for (string s : it)
        {
            cout << s << ",";
        }
        cout << "]";
    }
}

int main()
{
    Solution s;
    vector<string> v={"eat","tea","tan","ate","nat","bat"};
    // vector<string> v = {"bdddddddddd","bbbbbbbbbbc"};
    vector<vector<string>> ans;
    ans=s.groupAnagrams(v);

    printVector(ans);
}
