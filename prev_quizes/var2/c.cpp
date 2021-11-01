#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct heap {
    int a[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        a[i] = x;
        int p = (i - 1) / 2;
        while(i && a[i] < a[p]) {
            swap(a[i], a[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    int extract() {
        int top = a[0];
        if(top < 97) top += 27;
        a[0] = a[--hs];
        int i = 0;
        while(2 * i + 1 < hs) {
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            if(c2 < hs && a[c2] < a[c1] && a[c2] < a[i]) {
                swap(a[c2], a[i]);
                i = c2;
            } else if(a[c1] < a[i]) {
                swap(a[c1], a[i]);
                i = c1; 
            } else break;
        }
        return top;
    }

};

int main(){
    int n;
    cin >> n;
    heap h;
    string s = "aeoui";
    for(int i = 0; i < n; ++i) {
        char c; cin >> c;
        int l = int(c);
        if(s.find(c) != string::npos) l -= 27;
        h.add(l);
    }

    for(int i = 0; i < n; ++i) {
        cout << char(h.extract());
    } 
}