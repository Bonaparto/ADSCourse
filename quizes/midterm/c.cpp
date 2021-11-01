#include <bits/stdc++.h>
using namespace std;
 
struct Node {
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = nullptr;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node *head = nullptr;
    int sz = 0;
  public:
 
    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
      Node * node = new Node(x);
      if(head == NULL) {
        head = node;
      } else {
        node->prev = head;
        head = node;
      }
      int minval = x;
      Node * temp = head;
      sz++;
      temp = temp->prev;
      while(temp != NULL && minval == x) {
        if(temp->value <= minval){
           minval = temp->value;
           break;
        }
        temp = temp->prev;
      }
      
      
      if(temp == NULL) node->ans = -1;
      else node->ans = minval;
      
      return node->ans;         
    }
 
}st;
 
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << st.push(x) << " ";
  }
}