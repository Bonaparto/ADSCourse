#include <iostream>
#include <vector>
using namespace std;

void pi(string s) {
    int n = s.length();
    vector <int> pi(n);
    cout << 0 << " ";
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
        cout << j << " ";
    }
}

int main() {
    string s;
    cin >> s;
    pi(s);
}