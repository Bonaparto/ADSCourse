#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <string> d, t, e;
    int n; string s;
    while(cin >> n) {
        cin >> s;
        if(n == 9) d.push(s);
        else if (n == 10) t.push(s);
        else e.push(s);
    }
    while(!d.empty()) {
        cout << "9 " << d.front() << endl;
        d.pop();
    }
    while(!t.empty()) {
        cout << "10 " << t.front() << endl;
        t.pop();
    }
    while(!e.empty()) {
        cout << "11 " << e.front() << endl;
        e.pop();
    }
}