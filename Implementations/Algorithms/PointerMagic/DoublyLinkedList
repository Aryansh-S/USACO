#include <bits/stdc++.h>
using namespace std;

struct node{
  int val; node* prev = NULL, nxt = NULL; 
};

struct LL{
  node* head, tail; 
  void push_back(int val){
    node* tmp = new node; 
    tmp->val = val; tmp->nxt = NULL; tmp->prev = tail; 
    if(head == NULL){
      head = tail = tmp; 
    }
    else{
      tail->nxt = tmp; tail = tail->nxt; 
    }
  }
  void push_front(int val){
    node* tmp = new node; 
    tmp->val = val; tmp->nxt = head; tmp->prev = NULL; 
    if(tail == NULL){
      head = tail = tmp; 
    }
    else{
      head->prev = tmp; head = head->prev; 
    }
  }
  int operator[](int n){
    node* tptr = head; 
    while(n--) tptr = tptr->nxt; 
    return tptr->val;
  }
};

LL test;

int main(){
  
  test.push_back(1); test.push_back(2); cout << test[1] << "\n";
  
  return 0;
}
