#include <iostream>
#include <map>
using namespace std;

map <long long, int> mp;
map <long long, int> mp1;
long long p[32];
const long long q = 1e18 + 7;

void h(string s) {
    int n = s.size();
    long long h[n];
    for(int i = 0; i < n; ++i) {
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0) h[i] += h[i-1];
        h[i] %= q;
    }
    if(mp[h[n-1]] == 0) {
        mp[h[n-1]]++;
        cout << "OK" << endl;
    } else {
        cout << s << mp[h[n-1]]++ << endl;   
    }
}

int main(){

    int n;
    cin >> n;
    p[0] = 1;
    for(int i = 1; i < 32; ++i) p[i] = (p[i-1] * 31) % q; 
    while(n--) {
        string s;
        cin >> s;
        h(s);
    }
}