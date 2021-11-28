#include <iostream>
#include <map>
using namespace std;

void solve() {
    map <long long, int> mp;
    int n, m, ans = 0;
    cin >> n >> m;
    string s, t = "";
    cin >> s;
    long long q = 1e18 + 9, p[n], h[n]; 
    p[0] = 1;

    for(int i = 1; i < n; ++i) p[i] = (p[i-1] * 31) % q;
    
    for(int i = 0; i < n; ++i) {
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0) h[i] += h[i-1];
        h[i] %= q;
        long long temp = h[i];
        if(i > m - 1) {
            temp -= h[i-m];
            temp /= p[i-m+1];
        }
        if(i >= m - 1){
            mp[temp]++;
            if(mp[temp] == 1) ans++;
            // cout << h[i] << " " << h[i-m]  << " " << p[i-m+1] << " " << i << " " << ans << endl;
        }
    } 
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}