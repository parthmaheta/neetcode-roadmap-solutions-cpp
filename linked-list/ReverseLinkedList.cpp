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

class Solution
{
public:
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

void print(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        cout << " " << ptr->val;
        ptr = ptr->next;
    }
}

int main()
{
    ListNode *head = new ListNode(10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);

    print(head);
    cout << endl;
    Solution s;
    head = s.reverseList(head);
    print(head);
}