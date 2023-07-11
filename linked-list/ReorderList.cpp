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
    void reorderList(ListNode *head)
    {
       
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        return;

        ListNode *fast = head;
        ListNode *slow = head;


        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != NULL)
                fast = fast->next;               
        }
        ListNode *mid = reverseList(slow);
        ListNode *ptr = head;

        while (mid!=slow)
        {
          
            ListNode *node1 = ptr->next;
            ListNode *node2 = mid->next;
            ptr->next = mid;
            mid->next=node1;
            ptr = node1;
            mid=node2;
        }
       
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *current = head;
        while (current != NULL)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
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
    s.reorderList(head);
    print(head);
}