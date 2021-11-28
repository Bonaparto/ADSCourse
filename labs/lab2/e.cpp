#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct node {
    long long val;
    node * prev;
    node * next;
    node(long long x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct list {
    node * head;
    node * tail;
    list() {
        head = NULL;
        tail = NULL;
    }

    node * findnearest(long long v) {
        node * temp = head;
        while(temp != NULL) {
            if(temp->val >= v) break;
            temp = temp->next;
        }
        return temp;
    }

    node * find(long long v) {
        node * temp = head;
        while(temp != NULL) {
            if(temp->val == v) break;
            temp = temp->next;
        }
        return temp;
    }

    void push(long long v) { 
        node * newobj = new node(v);
        if(head == NULL) {
            head = tail = newobj;
        } else {
            node * temp1 = findnearest(v);
            if(temp1 == NULL) {
                tail->next = newobj;
                newobj->prev = tail;
                tail = newobj;
            } else if(temp1->prev != NULL) {
                temp1->prev->next = newobj;
                newobj->prev = temp1->prev;
                newobj->next = temp1;
                temp1->prev = newobj;
            } else if(temp1->prev == NULL) {
                temp1->prev = newobj;
                newobj->next = temp1;
                head = newobj;
            }
        }
    }

    void del(long long v) {
        node * temp = find(v);
        if(temp == NULL) {
            fout << "ERROR" << endl;
            exit(0);
        } else {
            if(temp->prev != NULL && temp->next != NULL) {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            } else if(temp->prev == NULL && temp->next != NULL) {
                head->next->prev = NULL;
                head = head->next;
            } else if(temp->prev != NULL && temp->next == NULL) {
                tail->prev->next = NULL;
                tail = tail->prev;
            } else head = tail = NULL;
        }
    }

    void print() {
        if(head == NULL) fout << "EMPTY";
        else {
            node * temp = head;
            while(temp != NULL) {
                fout << temp->val << " ";
                temp = temp->next;
            }
        }
        return;
    }
};

int main(){
    char c; long long a;
    list * l = new list();
    while(fin >> c >> a) {
        if(c == '+') {
            l->push(a);
        } else { 
            l->del(a);
        }
    }
    l->print();
}