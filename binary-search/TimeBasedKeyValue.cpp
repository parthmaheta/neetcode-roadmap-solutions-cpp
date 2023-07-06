#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TimeMap
{
    unordered_map<string,vector<pair<string,int>>> umap;
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {

        umap[key].push_back(pair<string,int>(value,timestamp));
    }

    string get(string key, int timestamp)
    {
        if(umap.find(key)!=umap.end()){
              vector<pair<string,int>> v=umap[key];
              int start=0;
              int end=v.size()-1;
              string answer="";
 
              while(start<=end){
                int mid=(start+end)/2;
                if(v[mid].second==timestamp){
                    return v[mid].first;
                }
                else if(v[mid].second<timestamp){
                    start=mid+1;
                    answer=v[mid].first;
                }
                else{
                   end=mid-1;
                }
              }         
              return answer;
        }
        return "";
    }

     // Another Approach

    //  unordered_map<string,map<int,string>> umap;
    // TimeMap() {}
    // void set(string key, string value, int timestamp) {
    //     umap[key].insert({-1*timestamp,value});
    // }
    // string get(string key, int timestamp) {
    //     if(!umap.count(key)) return "";
    //     auto it=umap[key].lower_bound(-1*timestamp);
    //     return (*it).second;
    // }
    
};

int main()
{
    TimeMap timeMap =  TimeMap();
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    cout<<timeMap.get("foo", 1)<<"\n";         // return "bar"
    cout<<timeMap.get("foo", 3)<<"\n";         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    cout<<timeMap.get("foo", 4)<<"\n";         // return "bar2"
    cout<<timeMap.get("foo", 5);
    cout<<timeMap.get("foo", 0);
}