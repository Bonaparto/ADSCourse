#include <iostream>
using namespace std;

void check(string s, string p) {
    int n = s.size();
    int m = p.size();
    long long q = 1e64;
    long long h[n];
    long long pm[n];
    pm[0] = 1;
    for(int i = 1; i < n; ++i) pm[i] = (pm[i-1] * 31) % q;

    for(int i = 0; i < n; ++i) {
        h[i] = ((s[i] - 'a' + 1) * pm[i]) % q;
        if(i > 0) h[i] += h[i-1];
        h[i] %= q;
    }

    long long ph = 0;
    for(int i = 0; i < m; ++i) {
        ph = (ph + ((p[i] - 'a' + 1) * pm[i]) % q) % q;
    }

    for(int i = 0; i + m - 1 < n; ++i) {
        int j = i + m - 1;
        long long cur = h[j];
        if(i > 0) cur -= h[i-1];
        // cout << cur << " " << (ph * pm[i]) % q << endl;
        if((ph * pm[i]) % q == cur && s.substr(i, m) == p) {
            cout << i << " ";
        }
    }
}

int main() {    
    string s, p;
    cin >> s >> p;
    check(s, p);
}