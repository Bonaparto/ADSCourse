#include <iostream>
using namespace std;

const int N = 1e5 + 5; 
int n;

struct heap {
    int h[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        if(hs == n) {
            cout << -1 << endl;
            return;
        }
        int i = hs++;
        h[i] = x;
        int p = (i - 1) / 2;
        while(i && h[i] > h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = (i - 1) / 2;
        }
        cout << i + 1 << endl;
    }

    void extract() {
        if(hs == 0) {
            cout << -1 << endl;
            return;
        }
        int mx = h[0];
        if(hs == 1) {
            cout << 0 << " " << mx << endl;
            hs--;
            return;
        }
        h[0] = h[--hs];
        int i = 0;
        while(2 * i + 1 < hs) {
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            if(c2 < hs && h[c2] > h[c1] && h[c2] > h[i]) {
                swap(h[c2], h[i]);
                i = c2;
            } else if(h[c1] > h[i]) {
                swap(h[c1], h[i]);
                i = c1; 
            } else break;
        }
        cout << i + 1 << " " << mx << endl;
    }

    void print() {
        for(int i = 0; i < hs; ++i) {
            cout << h[i] << " ";
        }
    }
};

int main(){
    int m;
    heap h;
    cin >> n >> m;
    while(m--) {
        int x; cin >> x;
        if(x == 1) h.extract();
        else {
            int y; cin >> y;
            h.add(y);
        } 
    }
    h.print();
}