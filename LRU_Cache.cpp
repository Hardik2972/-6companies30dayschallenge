#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
struct Listode {
    int val;
    Listode* next;
    Listode* prev;
    Listode(int value) : val(value), next(nullptr), prev(nullptr) {}
};



class LRUCache {
public:
    Listode* head = new Listode(0);
    Listode* tail = new Listode(0);
    int n;
    unordered_map<int,Listode*> m;
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        n=capacity;
    }
    
    int get(int key) {
        
        if(m.find(key)!=m.end()){
            Listode* curr = m[key];
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next=head->next;
            curr->prev=head;
            head->next->prev=curr;
            head->next = curr;
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Listode* curr = m[key];
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->val=value;
            curr->next=head->next;
            curr->prev=head;
            head->next->prev=curr;
            head->next = curr;
            return;
        }
        Listode* newNode = new Listode(value);
        if(m.size()==n){
            for(auto it:m){
                if(it.second==tail->prev){
                    m.erase(it.first);
                    break;
                }
            }
            tail->prev->prev->next=tail;
            tail->prev=tail->prev->prev;
        }
        newNode->next=head->next;
        newNode->prev=head;
        head->next->prev=newNode;
        head->next = newNode;
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */