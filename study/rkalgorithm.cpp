#include <iostream>
using namespace std;

bool check(string s, string pat) {
    
    long long n = s.size();
    long long h[n];
    long long p[n];
    long long q = (1 << 30) + 1;
    p[0] = 1;

    for(long long i = 1; i < n; ++i) p[i] = (p[i-1] * 31) % q;

    for(long long i = 0; i < n; ++i) {
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0) h[i] += h[i-1];
        h[i] = h[i] % q;
    }

    long long ph = 0;
    long long m = pat.size();

    for(long long i = 0; i < m; ++i) {
        ph = (ph + ((pat[i] - 'a' + 1) * p[i]) % q) % q;
    }

    bool res = 0;

    for(long long i = 0; i + m - 1 < n; ++i) {
        long long j = i + m - 1;
        long long cur = h[j];
        if(i > 0) cur -= h[i-1];
        if((ph * p[i]) % q == cur && s.substr(i, m) == pat) {
            res = true;
            break;
        }
    }
    return res;
} 

int main(){
    string s, p;
    cin >> s >> p;
    cout << check(s, p);
}