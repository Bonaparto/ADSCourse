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
        while(i && a[i] > a[p]) {
            swap(a[i], a[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    long long multiplication() {
        return a[0] * a[1] * a[2];
    }

};

int main(){
    int n;
    cin >> n;
    heap h;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        h.add(x);
        if(i < 2) cout << -1 << endl;
        else cout << h.multiplication() << endl;
    }
}