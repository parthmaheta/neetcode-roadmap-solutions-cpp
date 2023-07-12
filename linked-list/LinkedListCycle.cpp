#include <iostream>

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

void addCycle(ListNode * head,ListNode *cycle){
    ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = cycle;
    
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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }
};
int main()
{
    ListNode *head1 = new ListNode(9);
    push(head1, 7);
    push(head1, 9);
    push(head1, 10);
    push(head1, 20);
    push(head1, 20);
    ListNode* cycle=head1->next->next->next;
    addCycle(head1,cycle);

    Solution s;
     cout<<s.hasCycle(head1);
}