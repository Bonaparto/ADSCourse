#include <iostream>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] > a[ans]) ans = i;
    }
    cout << ans + 1;
}