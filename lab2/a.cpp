#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct node {
    long long cnt;
    string val;
    node * prev;
    node * next;
    node(string s) {
        val = s;
        cnt = 1;
        prev = NULL;
        next = NULL;
    }
};

struct mp {
    node * head;
    node * tail;
    mp() {
        head = NULL;
        tail = NULL;
    }

    node * find(string s) {
        node * temp = head;
        node * result = NULL;
        while(temp != NULL) { 
            if(temp->val == s) {
                result = temp;
                break;
            }
            temp = temp->next;
        }
        return result;
    }

    node * findnearest(string ss) {
        node * temp = head;
        while(temp != NULL) {
            if(compare(ss, temp->val)) break;l;
            temp = temp->next;
        }
        return temp;
    }

    bool compare(string a, string b) {
        for(long long i = 0; i < min(a.size(), b.size()); ++i) {
            if(a[i] > b[i]) return 0;
            else if(a[i] < b[i]) return 1;
        }
        if(a.size() < b.size()) return 1;
        return 0;
    }

    void addNew(string s) {
        node * temp = find(s);
        if(temp == NULL) {
            node * newObj = new node(s);
            if(head == NULL) {
                head = tail = newObj;
            } else {
                node * temp1 = findnearest(s);
                if(temp1 == NULL) {
                    tail->next = newObj;
                    newObj->prev = tail;
                    tail = newObj;
                } else if(temp1->prev == NULL ) {
                    temp1->prev = newObj;
                    newObj->next = temp1;
                    head = newObj;
                } else {
                    temp1->prev->next = newObj;
                    newObj->next = temp1;
                    newObj->prev = temp1->prev;
                    temp1->prev = newObj;
                }
            }
        } else {
            temp->cnt++;
        }
    }

    void print() {
        node * temp = head;
        while(temp != NULL) {
            fout << temp->val << " " << temp->cnt << endl;
            temp = temp->next;
        }
    }

};

int main() {
    string s;
    mp * m = new mp();
    while(fin >> s) {
        m->addNew(s);
    }
    m->print();
}