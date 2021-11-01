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

    int extract() {
        int top = a[0];
        a[0]--;
        return top;
    }

    void sift_down() {
        int i = 0;
        while(2 * i + 1 < hs) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(r < hs && a[r] > a[l] && a[r] > a[i]) {
                swap(a[i], a[r]);
                i = r;
            } else if(l < hs && a[l] > a[i]) {
                swap(a[i], a[l]);
                i = l;
            } else break;
        }
    }

    void print() {
        for(int i = 0; i < hs; ++i) cout << a[i] << " ";
        cout << endl;
    }
};  

int main(){
    int n, x; 
    long long ans = 0;
    cin >> n >> x;
    heap h;
    while(n--) {
        int y; cin >> y;
        h.add(y);
    }
    
    while(x--) {
        ans += h.extract();
        h.sift_down();
    }
    cout << ans;
}