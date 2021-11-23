#include <iostream>
#include <map>
using namespace std;

void solve() {
    map <int, int> mp;
    int n, m, ans = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    long long q = 1e64, p[n], h[n]; 
    p[0] = 1;

    for(int i = 1; i < n; ++i) p[i] = p[i-1] * 31;
    
    for(int i = 0; i < n; ++i) {
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0) h[i] += h[i-1];
        h[i] %= q;
        if(i >= m) {
            cout << h[i] << endl;
            if(i == m) {
                ans++;
                mp[h[i]]++;
                continue;
            } 
            h[i] /= p[i-m+2];
            h[i] -= h[i-m+2];
            if(mp[h[i]] == 0) ans++;
            mp[h[i]]++;
            cout << h[i] << endl;
            //cout << h << endl; 
        } 
    } 
    cout << ans << " " << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}