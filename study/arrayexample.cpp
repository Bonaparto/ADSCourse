#include <iostream>
using namespace std;


struct st { 
    private:
        int * a;
        int top;

    public:
    st(int n) { 
        top = -1;
        a = new int[n];
    }

    int getTop() { 
        if(top != -1) return a[top];
        else return -1;
    }

    void push_value(int x) {
        top++;
        a[top] = x;
    }

    void pop() {
        if(top != -1) {
            a[top] = 0;
            top--;
        } 
    }

};

int main(){
    int d[] = {1, 10, 2, 3, 4, 5};
    int n = sizeof(d) / sizeof(int);
    st s(n);
    for(int i = 0; i < n; ++i) {
        s.push_value(d[i]);
    }
    s.pop();
    cout << s.getTop() << endl;
}