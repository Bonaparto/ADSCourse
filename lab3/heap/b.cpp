#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct heap {
    int h[N];
    int hs;

    heap(){
        hs = 0;
    }

    void add(int x) {
        int i = hs++;
        h[i] = x;
        int p = (i - 1) / 2;
        while(i && h[i] > h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }

    void decrease(int num, int x) {
        num--;
        h[num] -= x;
        while(2 * num + 1 < hs) {
            int c1 = 2 * num + 1;
            int c2 = 2 * num + 2;
            if(c2 < hs && h[c1] < h[c2] && h[c2] > h[num]) {
               // cout << h[c2] << " kek" << endl;
                swap(h[c2], h[num]);
                num = c2;
            } else if(h[c1] > h[num]) {
               // cout << h[c1] << " lol" << endl;
                swap(h[c1], h[num]);
                num = c1;
            } else break;
        } 
        cout << num + 1 << endl;
    }

    void print() {
        int i = 0;
        while(i < hs) {
            cout << h[i] << " ";
            i++;
        }
    }
};

int main(){
    int n, m;
    heap he;
    cin >> n;
    while(n--) {
        int x; cin >> x;
        he.add(x);
    }
    cin >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        he.decrease(x, y);
    }
    he.print();
}