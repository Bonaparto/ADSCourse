#include <iostream>
using namespace std;
int main(){
    int n, ans = -10000;
    cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x > ans) ans = x;
    }
    cout << ans;
}