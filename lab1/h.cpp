#include <iostream>

using namespace std;

int cnt = 0;

struct gob {
    int val;
    gob * next;
    gob * prev;
    gob * front;
    gob * center1;
    gob * center2;
    gob(int x) {
        val = x;
        next = NULL;
        prev = NULL;
        front = NULL; 
        center1 = NULL;
        center2 = NULL;
    }
};

struct de {
    gob * current;
    de() {
        current = NULL;
    }

    void push(int x, char c) {
        gob * goblin = new gob(x);
        if(current == NULL) {
            current = goblin;
            current->center1 = current;
            current->center2 = NULL;
            current->next = NULL;
            current->prev = NULL;
            current->front = current;
        } else {
            if(c == '+') {
                if(cnt % 2 == 0) { 
                    goblin->center1 = current->center2;
                    goblin->center2 = NULL;
                    goblin->front = current->front;
                } else {
                    goblin->center1 = current->center1;
                    if(cnt == 1) goblin->center2 = goblin;
                    else goblin->center2 = current->center1->next;
                    goblin->front = current->front;
                }
                goblin->prev = current;
                goblin->next = NULL;
                current->next = goblin;
                current = goblin;
            } else {
                if(cnt % 2 == 0) {
                    goblin->prev = current->center1;
                    goblin->next = current->center2;
                    current->center1->next = goblin;
                    current->center2->prev = goblin;
                    current->center1 = goblin;
                    current->center2 = NULL;
                } else {
                    if(cnt == 1) {
                        goblin->prev = current;
                        goblin->next = NULL;
                        goblin->center1 = current;
                        goblin->front = current;
                        goblin->center2 = goblin;
                        current->next = goblin;
                        current->center2 = goblin;
                        current = goblin;
                    } else {
                        goblin->center1 = current->center1;
                        goblin->prev = current->center1;
                        goblin->next = current->center1->next;
                        current->center2 = goblin;
                        current->center1->next->prev = goblin;
                        current->center1->next = goblin;
                    }
                }         
            }
        }
        cnt++;
    }

    void pop() {
        cout << current->front->val << endl;
        if(cnt == 1) {
            current = NULL;
        } else {
            if(cnt % 2 == 0) {
                current->center1 = current->center2;
                current->center2 = NULL;
            } else {
                current->center2 = current->center1->next;
            }
            current->front = current->front->next;
            current->front->prev = NULL;
        }
        cnt--;
    }
};

int main(){
    int n, x; char c;
    de d;
    cin >> n;
    while(n--) {
        cin >> c;
        if(c == '+' || c == '*') {
            cin >> x;
            d.push(x, c);
        } else {
            d.pop();
        }
    }
}