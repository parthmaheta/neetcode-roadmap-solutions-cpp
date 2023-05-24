#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {

         if(s.size()!=t.size()){
            return false;
         }

        unordered_map<char,int> map;
        for(char ch:s){            
           if(map.find(ch)!=map.end()){
            map[ch]++;
           }else{
            map.insert(pair<char,int>(ch,1));
           }
        }

        for(char ch:t){
            if(map.find(ch)!=map.end()){
                if(map[ch]==0)
                 return false;
                 map[ch]--;
            }else{
                return false;
            }
        }


       
        return true;
    }
};

int main(){
   Solution s;
   cout<<"hellowe, a : "<<s.isAnagram("hellowe","a")<<"\n";
   cout<<"parth, harpt : "<<s.isAnagram("parth","harpt")<<"\n";
   cout<<"harpt, parth : "<<s.isAnagram("harpt","parth")<<"\n";
   cout<<"rat, car : "<<s.isAnagram("rat","car")<<"\n";
   cout<<"123, 321 : "<<s.isAnagram("123","321")<<"\n";
   cout<<" jaya, aajy : "<<s.isAnagram("jaya","aajy")<<"\n";
   cout<<" hwlo , hwlos : "<<s.isAnagram("hwlo","hwlos")<<"\n";
   cout<<" "" , "" : "<<s.isAnagram("s","")<<"\n";

   
}