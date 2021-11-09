#include <iostream>
using namespace std;

int hashed(string s) {
    int p = 1;
    int q = 1e9 + 7;
    int h = 0;
    for(int i = 0; i < s.size(); ++i) {
        h += ((s[i] - 'a' + 1) * p) % q;
        p = (p * 31) % q;
    }
    return h;
}

int main(){
    string s; 
    cin >> s;
    int h = hashed(s);
    cout << h;
}