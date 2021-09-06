#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
    node * prev;
    node(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct st { 
    private:
        node * tail;  

    public:
    st() { 
        tail = NULL;
    }

    int getTop() { 
        if(tail != NULL) return tail->val;
        return -1;
    }

    void push_value(int x) {
        node * item = new node(x);
        if(tail == NULL) tail = item;
        else { 
            item->prev = tail;
            tail = item;
        }
    }

    void pop() {
        if(tail != NULL && tail->prev != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else tail = NULL;
    }
};

int main(){
    int d[] = {1, 10, 2, 3, 4, 5};
    int n = sizeof(d) / sizeof(int);
    st s;
    for(int i = 0; i < n; ++i) {
        s.push_value(d[i]);
    }
    for(int i = 0; i < n; ++i) {
        cout << s.getTop() << endl;
        s.pop();
    }
    if(s.getTop() == -1) {
        cout << "Stack is empty";
        return 0;
    }
}