#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> max_substring_length(string s, string s1) {
    int ans = 0;
    string s2 = s + "#" + s1;
    int n = s2.length();
    vector <int> pi(n);
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s2[i] != s2[j]) {
            j = pi[j-1];
        }
        if(s2[i] == s2[j]) j++;
        pi[i] = j;
        if(j > ans) ans = j;
    }
    return pi;
}

int main() {
    string s, s1;
    cin >> s >> s1;
    vector <int> v = max_substring_length(s, s1);
    for(int i = v.size() - 1; i > int(s.length()); --i) {
        string temp = s;
        rotate(temp.begin(), temp.begin() + v[i], temp.end());
        if(temp == s1) {
            cout << s.length() - v[i];
            return 0;
        }
    }
    cout << -1;
    // rotate(s.begin(), s.begin() + ans, s.end());
    // cout << s << " " << ans << endl;
    // if(s == s1) cout << s.length() - ans;
    // else cout << -1;
}