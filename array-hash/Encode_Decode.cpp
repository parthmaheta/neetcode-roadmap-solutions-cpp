#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
   public:
   string encode(vector<string> &strs){
          string ans;
          for(string s:strs){
            ans.append(to_string(s.length())+"#"+s);
          }
          return ans;
   }

   vector<string> decode(string &str){
      vector<string> ans;
      if(str=="")
      return ans;

      int index=0;
      while(index<str.find_last_of('#'))
      {
        int current=0;
        while(str[index+current]!='#'){
            current++;
        }
        int charlength=stoi(str.substr(index,current));
    
        ans.push_back(str.substr(index+current+1, charlength));
        index=index+current+charlength+1;
      }

      return ans;
   }

};
string printVector(vector<string> p){
    string ans;
    for(auto i:p){
      ans.append(i+" ");       
    }
    return ans;
}

int main(){
    Solution obj;
    vector<string> s{"hellow","hi","888","0000",";:+-","1","88#","853243123856782#"};
    string j=obj.encode(s);
    cout<<j<<"\n";
   vector<string> p=obj.decode(j);
    cout<<printVector(p);
    
}