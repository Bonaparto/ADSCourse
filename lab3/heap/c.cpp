#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct heap {
    int h[N];
    int hs;

    heap() {
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        h[i] = x;
    }

    void extract() {
        int mx = h[0];
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
};

int main(){
    int n;
    heap h;
    cin >> n;
    for(int i = 0; i < n; ++i) { 
        int x; cin >> x;
        h.add(x);
    }

    while(--n) h.extract();
}