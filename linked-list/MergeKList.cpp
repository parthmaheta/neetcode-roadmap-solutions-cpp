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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        return nullptr;
        
        while(lists.size()>1){
            vector<ListNode*> mergedList={};  
            for(int index=0;index<lists.size();index+=2){
                ListNode* l1=lists[index];

                ListNode* l2= index+1<lists.size() ? lists[index+1] : nullptr ;
                mergedList.push_back(mergeList(l1,l2));
            }
            lists=mergedList;
        }
        return lists[0];
    }
   
   ListNode* mergeList(ListNode* l1,ListNode* l2){
       ListNode* dummy=new ListNode(0);
       ListNode* ptr=dummy;
       while(l1&&l2){
        if(l1->val>l2->val)
        {
                ptr->next = l2;
                l2 = l2->next;
        }
        else
        {
                ptr->next = l1;
                l1 = l1->next;
        }
        ptr=ptr->next;
       }
       if(l1)
       ptr->next=l1;
       if(l2)
       ptr->next=l2;
       return dummy->next;
   }

};

int main(){
    Solution s;
    ListNode* head1=new ListNode(10);
    push(head1,20);
    push(head1,30);
    push(head1,40);
    push(head1,50);
    
    ListNode* head2=new ListNode(1);
    push(head2,12);
    push(head2,30);
    push(head2,45);
    push(head2,51);
    ListNode* head3=new ListNode(11);
    push(head3,15);
    push(head3,20);
    push(head3,30);
    push(head3,60);

    vector<ListNode*> v={head1,head2,head3};
    
    ListNode* head=s.mergeKLists(v);
    print(head);

}