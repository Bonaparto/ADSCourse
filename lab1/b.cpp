#include <iostream>
using namespace std;

long long cnt = 0;

struct node {
    long long val;
    node * next;
    node * front;
    node(long long x) {
        val = x;
        next = NULL;
        front = NULL;
    }
};

struct que {
    node * current;
    que() { 
        current = NULL;
    }

    void getFront() {
        if(current != NULL) {
            cout << current->front->val << endl;
        } else cout << "error" << endl;
    }

    void pop() {
        // if(current == NULL) cout << "error" << endl;
        // else if(current->front->next == NULL) {
        //     cout << current->val << endl;
        //     current = NULL;
        // } else {
        //     cout << current->front->val << endl;
        //     current->front = current->front->next;
        // }
        if(current != NULL && current->front->next != NULL) {
            cout << current->front->val << endl;
            current->front = current->front->next;
        } else if(current != NULL && current->front->next == NULL) {
            cout << current->val << endl;
            current = NULL;
        } else {
            cout << "error" << endl;
            return;
        }
        cnt--;
        return;
    }

    void push(long long y) {
        node * item = new node(y);
        if (current == NULL) {
            current = item;
            current->front = item;
            current->next = NULL;
        } else {
            item->next = NULL;
            item->front = current->front;
            current->next = item;
            current = item;
        }
        cout << "ok" << endl;
        cnt++;
    }

    void clear() {
        while(1) {
            if (current == NULL || current->front->next == NULL) {
                current = NULL;
                break;
            }
            current->front = current->front->next;
        }
        cnt = 0;
        cout << "ok" << endl;
    }

};

int main(){
    string s = "";
    que z;
    while(s != "exit") {
        cin >> s;
        if(s == "push") {
            long long x; cin >> x;
            z.push(x);
        }
        else if(s == "pop") { 
            z.pop();
        }
        else if(s == "front") { 
            z.getFront();
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