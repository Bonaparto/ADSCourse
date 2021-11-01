#include <iostream>
using namespace std;

int binary_search(int a[], int l, int r, int x, bool f) {
    while(l < r) {
        int mid = (r + l) / 2;
        if(a[mid] == x) {
            return mid;
        } else {
            if(f) {
                if(a[mid] > x) r = mid;
                else l = mid + 1;
            } else {
                if(a[mid] > x) l = mid + 1;
                else r = mid;
            }
        }
    }
    return -5;
}

int main(){
    int t;
    cin >> t;
    int a[t];
    for(int i = 0; i < t; ++i) cin >> a[i];
    int n, m;
    cin >> n >> m;
    int b[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < t; ++i) {
        bool f = 0;
        for(int j = 0; j < n; ++j) {
            int l = 0, r = m;
            bool f1 = 1;
            if(j % 2 == 0) f1 = 0;
            int mid = binary_search(b[j], l, r, a[i], f1);
            if(mid != -5) {
                cout << j << " " << mid << endl;
                f = 1;
                break;
            }
        }
        if(!f) cout << -1 << endl;
    }
}