#include <iostream>
#include <stack>
using namespace std;

// ifstream fin("intput.txt");
// ofstream fout("output.txt");

const int N = 1e6;

typedef pair<int,int> pii;

int main() {
    int n;
    string s;
    cin >> n >> s;
    stack <char> q;

    for(int i = 0; i < n; ++i) {
        if(q.empty() || q.top() == s[i]) q.push(s[i]);
        q.pop();
    }
    if(q.empty()) {
        if(s[s.length() - 1] == 'S') cout << "KATSURAGI";
        else cout << "SAKAYANAGI";
        return 0;
    }
    if(q.top() == 'S') cout << "SAKAYANAGI";
    else cout << "KATSURAGI";
}