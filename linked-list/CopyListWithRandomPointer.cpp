#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void push(Node *head, int val)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new Node(val);
}
void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << " " << ptr->val;
        ptr = ptr->next;
    }
}

class Solution
{
public:
    Node *mapRandomList(Node *head)
    {
        if (!head)
            return head;
        unordered_map<Node *, Node *> map;
        Node *ptr = head;
        while (ptr)
        {
            if (!map[ptr])
            {
                map[ptr] = new Node(ptr->val);
                ptr = ptr->next;
            }
        }
        ptr = head;
        while (ptr)
        {
            map[ptr]->next = ptr->next ? map[ptr->next] : nullptr;
            map[ptr]->random = ptr->random ? map[ptr->random] : nullptr;
            ptr = ptr->next;
        }
        return map[head];
    }
};
int main()
{
    Node *head = new Node(7);
    push(head, 13);
    push(head, 11);
    push(head, 10);
    push(head, 1);

    print(head);
    cout << endl;

    Solution s;
    cout<<endl<<head;
    head = s.mapRandomList(head);
    cout<<endl<<head<<endl;
    print(head);
}