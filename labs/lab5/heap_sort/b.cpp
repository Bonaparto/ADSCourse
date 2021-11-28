#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct heap {
    int a[N];
    int hs;

    heap() {
        hs = 0;
    }

    void extract() {
        int top = a[0], i = 0;
        a[0] = a[--hs];
        while(2 * i + 1 < hs) {
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            if(c2 < hs && a[c2] > a[i] && a[c2] > a[c1]) {
                swap(a[i], a[c2]);
                i = c2;
            } else if(c1 < hs && a[c1] > a[i]) {
                swap(a[i], a[c1]);
                i = c1;
            } else break;
        }
        cout << top << endl;
    }

    void insert(int x) {
        int i = hs++;
        a[i] = x;
        int p = (i - 1) / 2;
        while(i && a[i] > a[p]) {
            swap(a[i], a[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    void print() {
        for(int i = 0; i < hs; ++i) cout << a[i] << " ";
        cout << endl;
    }
};

int main(){
    int n;
    heap h;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x == 0) {
            int k; cin >> k;
            h.insert(k);            
        } else h.extract();
        //h.print();
    } 
}