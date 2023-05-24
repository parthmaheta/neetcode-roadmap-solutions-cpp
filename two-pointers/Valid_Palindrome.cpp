#include <iostream>
#include <string>

using namespace std;
    
class Solution{
  public:
  bool isPalindrome(string s)
  {
      int start = 0, end = s.length() - 1;

      while (start < end)
      {
          if (!isalnum(s[start]))
              start++;
          else if (!isalnum(s[end]))
              end--;
          else if (tolower(s[start]) != tolower(s[end]))
              return false;
          else
          {
              start++;
              end--;
          }
      }

      return true;
  }
};


int main(){
    Solution s;
    cout<<s.isPalindrome("race a car");
    cout<<"\n";
    cout<<s.isPalindrome("A man, a plan, a canal: Panama");
}