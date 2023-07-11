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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *head = NULL;
        if (list1 == NULL && list2 == NULL)
            return NULL;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
      
         if (list1->val > list2->val)
        {
            head = list2;
            list2 = list2->next;
        }
        else
        {
            head = list1;
            list1 = list1->next;
        }
        ListNode* ptr=head;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val>list2->val){
                ptr->next=list2;
                list2=list2->next;
            }
            else{
                ptr->next=list1;
                list1=list1->next;
            }
            ptr=ptr->next;
        }
        if(list1==NULL)
        ptr->next=list2;
        else
        ptr->next=list1;


        return head;
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
    ListNode *head1 = new ListNode(10);
    push(head1, 20);
    push(head1, 30);
    push(head1, 40);
    push(head1, 50);

    ListNode *head2 = new ListNode(5);
    push(head2, 15);
    push(head2, 32);
    push(head2, 40);
    push(head2, 60);
    Solution s;
    head1 = s.mergeTwoLists(head1,head2);
    print(head1);
}