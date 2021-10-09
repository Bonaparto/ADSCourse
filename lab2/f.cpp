#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

long long cnt = 0;

struct node {
    string val;
    node * prev;
    node * next;
    node(string x) {
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

    node * findstring(long long l) {
        if(l == cnt + 1) return NULL;
        long long t = 0;
        node * temp = head;            
        while(--l){
            temp = temp->next;
        }  
        return temp;
    }

    void push(string s, long long l) { 
        node * newobj = new node(s);
        if(l > cnt + 1) {
            fout << "ERROR";
            exit(0);
        }
        if(head == NULL) {
            head = tail = newobj;
        } else {
            node * temp = findstring(l);
            if(temp == NULL) {
                tail->next = newobj;
                newobj->prev = tail;
                tail = newobj;
            } else if(temp->prev == NULL) {
                head->prev = newobj;
                newobj->next = head;
                head = newobj;
            } else {
                temp->prev->next = newobj;
                newobj->prev = temp->prev;
                newobj->next = temp;
                temp->prev = newobj;
            }
        }
        cnt++;
    }

    void change(string s, long long l) {
        if(l > cnt || l < 0) {
            fout << "ERROR";
            exit(0);
        }
        node * temp = findstring(l);
        temp->val = s;
    }

    void del(string s, long long l) {
        if(l > cnt || l < 0) {
            fout << "ERROR";
            exit(0);
        }
        node * temp = findstring(l);
        if(temp->prev == NULL && temp->next == NULL) {
            head = tail = NULL; 
        } else if(temp->prev == NULL) {
            temp->next->prev = NULL;
            head = temp->next;
        } else if(temp->next == NULL) {
            temp->prev->next = NULL;
            tail = tail->prev;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        cnt--;
    }

    void print() {
        if(head == NULL) fout << "EMPTY";
        else {
            node * temp = head;
            while(temp != NULL) {
                fout << temp->val << endl;
                temp = temp->next;
            }
        }
        return;
    }
};

int main(){
    char c; long long a; string s;
    list * l = new list();
    while(fin >> c >> a) {
        getline(fin, s);
        s.erase(0, 1);
        if(c == '+') {
            l->push(s, a);
        } else if(c == '*'){
            l->change(s, a);
        } else {
            l->del(s, a);
        }
    }
    l->print();
}