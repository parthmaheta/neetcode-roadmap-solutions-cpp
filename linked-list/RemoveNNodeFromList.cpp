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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *Dummy=new ListNode(1,head);
        ListNode *Next=head;
        for(int index=0;index<n;index++){
            if(Next==NULL)
            return head;
            Next=Next->next;
        } 
        
        ListNode* Slow=Dummy;
        while(Next!=NULL){
           Next=Next->next;
           Slow=Slow->next;
        }
        Slow->next=Slow->next->next;
        return Dummy->next;
    }
  

};
int main()
{
    ListNode *head = new ListNode(10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    push(head, 60);

    print(head);
    cout << endl;

    Solution s;
    head=s.removeNthFromEnd(head,3);
    print(head);
}