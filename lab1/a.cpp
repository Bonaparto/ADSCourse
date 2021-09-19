#include <iostream>
using namespace std;

long long cnt = 0;

// 1 
 
struct node {
    long long val; // 5
    node * prev;  // 4 <- 
    node(long long x) {
        val = x;
        prev = NULL;
    }
};

struct st {

    node * tail;
    st() { 
        tail = NULL;
    }

    // 1 <- 2 <- 3 

    void getTop() {
        if(tail != NULL) cout << tail->val << endl; 
        else cout << "error" << endl;
        return;
    }

    void pop() {
        if(tail == NULL) cout << "error" << endl;
        else if(tail->prev == NULL) {
            cout << tail->val << endl; 
            tail = NULL;
            cnt--;
        }
        else {
            cout << tail->val << endl;
            tail = tail->prev;
            cnt--;
        }
        return;
    }

    void push(long long y) {
        // tail = NULL;
        node * item = new node(y);
        // link = NULL, val = y;
        if(tail == NULL) { 
            tail = item;
            tail->prev = NULL;
        }
        else { 
            // 1 <- 2 <- 3
            item->prev = tail;
            tail = item;
        }
        cout << "ok" << endl;
        cnt++;
    }

    void clear() {
        while(1) {
            if(tail == NULL || tail->prev == NULL) {  
                tail = NULL;
                break;
            }
            tail = tail->prev;
        }
        cnt = 0;
        cout << "ok" << endl;
    }
    
};

int main(){
    string s = "";
    st z;
    while(s != "exit") {
        cin >> s;
        if(s == "push") {
            long long x; cin >> x;
            z.push(x);
        }
        else if(s == "pop") { 
            z.pop();
        }
        else if(s == "back") { 
            z.getTop();
        }
        else if(s == "size") { 
            cout << cnt << endl;
        }
        else if(s == "clear") { 
            z.clear();
        }
        else if(s == "exit"){
            cout << "bye" << endl;
        }
    }
}