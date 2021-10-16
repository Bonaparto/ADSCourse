#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int size = 0;

struct node {
    int val;
    node * prev;
    node * next;
    node(int x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct ll {
    node * head;
    node * tail;
    bool b;
    ll() {
        head = NULL;
        tail = NULL;
        b = 0;
    }

    void add(int x) {
        node * newObj = new node(x);
        if(head == NULL) {
            head = tail = newObj;
        } else {
            if(!b) {
                newObj->prev = tail;
                tail->next = newObj;
                tail = newObj;
            } else {
                newObj->next = head;
                head->prev = newObj;
                head = newObj;
            }
        }
        size++;
    }

    void reverse() {
        b = !b;
    }

    void print() {
        node * cur;
        if(!b) cur = head;
        else cur = tail;
        while(cur != NULL) {
            fout << cur->val << " ";
            if(!b) cur = cur->next;
            else cur = cur->prev;
        }
        fout << endl;
    }

};

int main(){
    int n;
    fin >> n;
    ll a;
    for(int i = 0; i < n; ++i) {
        int q; fin >> q;
        if(q == 1) {
            int y; fin >> y;
            a.add(y);
        } else {
            a.reverse();
        }
        a.print();
    }  
    a.print();
}