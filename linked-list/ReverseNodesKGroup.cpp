#include<iostream>
#include<vector>

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
class Solution{
    public:
    
     ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev=dummy;
        while(head) {
          ListNode* kthNode=getKthNode(head,k);    
          prev->next=kthNode ? kthNode:head;   
          if(kthNode){
          ListNode* kNext=kthNode->next;
          ListNode * ptr=head;
            while(ptr!=kNext){
                ListNode* next=ptr->next;
                ptr->next=prev;
                prev=ptr;
                ptr=next;
            }
            prev=head;
            head=kNext;
            prev->next=nullptr;
          }
          else{
            head=nullptr;
          }
        }
        return dummy->next;
    }

    ListNode* getKthNode(ListNode* head,int k){
        while(k>1){
            if(head==NULL)
            return NULL;
           head=head->next;
           k--;
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode* head=new ListNode(10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);
    push(head,60);
    head=s.reverseKGroup(head,3);
    print(head);
}