#include <iostream>
using namespace std;

long long cnt = 0;

struct node {
    long long val;
    node * next;
    node * prev;
    node * front;
    node (long long x) {
        val = x;
        next = NULL;
        prev = NULL;
        front = NULL; 
    }
};

struct de {
    node * current;
    de() {
        current = NULL;
    }

    void push_front(long long x) {
        node * item = new node(x);
        if (current == NULL) {
            current = item;
            current->prev = NULL;
            current->next = NULL;
            current->front = current;
        } else {
            current->front->prev = item;
            item->next = current->front;
            item->prev = NULL;
            current->front = item;
        }
        cnt++;
        cout << "ok" << endl;
    }

    void push_back(long long x) {
        node * item = new node(x);
        if (current == NULL) {
            current = item;
            current->prev = NULL;
            current->next = NULL;
            current->front = current;
        } else {
            item->prev = current;
            item->front = current->front;
            current->next = item;
            current = item; 
        }
        cnt++;
        cout << "ok" << endl;
    }

    void pop_front() {
        if (current != NULL && current->front->next != NULL) {
            cout << current->front->val << endl;
            current->front = current->front->next;
        } else if (current != NULL && current->front->next == NULL) {
            cout << current->val << endl;
            current = NULL;
        } else {
            cout << "error" << endl;
            return;
        }
        cnt--;
        if (cnt == 0) current = NULL;
        return;
    }

    void pop_back() { 
        if (current == NULL) cout << "error" << endl;
        else if (current->prev == NULL) {
            cout << current->val << endl; 
            current = NULL;
            cnt--;
        }
        else {
            cout << current->val << endl;
            current->prev->front = current->front; 
            current = current->prev;
            cnt--;
        }
        if (cnt == 0) current = NULL;
        return;
    }

    void front() {
        if (current != NULL) cout << current->front->val << endl;
        else cout << "error" << endl;
    }

    void back() {
        if (current != NULL) cout << current->val << endl;
        else cout << "error" << endl;
    }

    void size() {
        cout << cnt << endl;
    }

    void clear() {
        while(1) {
            if (current == NULL || current->prev == NULL) {
                current = NULL;
                break;
            }
            current = current->prev;
        }
        cout << "ok" << endl;
        cnt = 0;
    }
};
    
int main() {
    string s = "";
    de z;
    while (s != "exit") {
        cin >> s;
        if (s == "push_front") {
            long long x; cin >> x;
            z.push_front(x);
        }
        else if (s == "push_back") {
            long long x; cin >> x;
            z.push_back(x);
        }
        else if (s == "pop_front") {
            z.pop_front();
        }
        else if (s == "pop_back") { 
            z.pop_back();
        }
        else if (s == "back") { 
            z.back();
        }
        else if (s == "size") { 
            cout << cnt << endl;
        }
        else if (s == "clear") { 
            z.clear();
        }
        else if (s == "front") { 
            z.front();
        }
        else if (s == "exit"){
            cout << "bye" << endl;
        }
    }
}