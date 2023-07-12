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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if(l1==NULL&&l2==NULL)
         return NULL;
        int carry = 0;
        int ans = 0;
        if (l1)
        {
            ans += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            ans += l2->val;
            l2 = l2->next;
        }
        ListNode* ptr =new ListNode(ans % 10);        
        carry = ans / 10;
        ListNode* head=ptr;

        while (l1 || l2||carry!=0)
        {
            int ans = carry;
            if (l1)
            {
                ans += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                ans += l2->val;
                l2 = l2->next;
            }
            ptr->next =new ListNode(ans % 10);
            carry = ans / 10;
            ptr=ptr->next;
        }
        return head;
    }
};
int main()
{
    ListNode *head1 = new ListNode(9);
    push(head1, 7);
    push(head1, 9);
    ListNode *head2 = new ListNode(9);

    Solution s;
    head1 = s.addTwoNumbers(head1, head2);
    print(head1);
}