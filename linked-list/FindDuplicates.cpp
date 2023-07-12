#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push(ListNode *head, int val)
{
    ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new ListNode(val);
}

void print(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        cout << " " << ptr->val;
        ptr = ptr->next;
    }
}

class Solution
{
public:
     int findDuplicate(vector<int>& nums) {
        int fast=0;
        int slow=0;
        do{
           slow=nums[slow];
           fast=nums[nums[fast]];
        }while(fast!=slow);
        
        slow=0;
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;

    }
};
int main()
{
   
    vector<int> v={1,3,3,2,5,4};

    Solution s;
    cout<<s.findDuplicate(v);
}