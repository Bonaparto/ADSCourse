#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    while(m--) {
        int l1, r1, l2, r2, cnt = 0; cin >> l1 >> r1 >> l2 >> r2;
        for(int i = 0; i < n; ++i) {
            if(a[i] >= l1 && a[i] <= r1) cnt++;
        } 
        for(int i = 0; i < n; ++i) {
            if(a[i] >= l2 && a[i] <= r2 && !(a[i] >= l1 && a[i] <= r1)) cnt++;
        } 
        cout << cnt << endl;
    }
}