#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int max_repeat(string s) {
    int n = s.size();
    vector <int> pi(n); 
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    // cout << pi[n-1] << " " << n % (n - pi[n-1] != 0) << endl; 
    if(pi[n-1] < ceil(n / 2) || n % (n - pi[n-1]) != 0) return n;
    return n / (n - pi[n-1]);
}

int main(){
    string s;
    cin >> s;
    cout << max_repeat(s);
}