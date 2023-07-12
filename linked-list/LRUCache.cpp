#include<iostream>
#include<unordered_map>

using namespace std;

class Node{
    public:
    int key;
    int val;    
    Node *prev;
    Node *next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->prev=nullptr;
        this->next=nullptr;
   }
};

class LRUCache {
    int capacity;
    Node *left;
    Node *right;
    unordered_map<int,Node *> cache;

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->left=new Node(0,0);
        this->right=new Node(0,0);
        this->left->next=this->right;
        this->right->prev=this->left;
    }
    void insert(Node * ptr){
            ptr->next=this->right;
            ptr->prev=this->right->prev;
            this->right->prev->next=ptr;
            this->right->prev=ptr;
    }

    void remove(Node *ptr){
          Node* prv=ptr->prev;
          Node* nxt=ptr->next;
          prv->next=nxt;
          nxt->prev=prv; 

    }
    int get(int key) {
        if(cache.count(key)==1)
        {
         this->remove(cache[key]);       
         this->insert(cache[key]);       
         return cache[key]->val;            
        }  
        
        return -1;

    }
    
    void put(int key, int value) {
        if(cache.count(key)==1)
        {
            this->remove(cache[key]);
        }
            cache[key]=new Node(key,value);
            this->insert(cache[key]);

        if(cache.size()>capacity){
            Node *LRU=this->left->next;
            this->remove(LRU);
            cache.erase(LRU->key);
        }    
    }
};


int main(){

  LRUCache* obj = new LRUCache(3);
  int param_1 = obj->get(1);
  obj->put(2,20);

}
