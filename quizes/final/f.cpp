#include <iostream>
#include <vector>
using namespace std;

// ifstream fin("input.txt");
// ofstream fout("output.txt");

const int N = 1e6;

typedef pair<int,int> pii;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s; int x;
        cin >> s >> x;
        int size = s.length();
        vector<int> pi(size);
        // fout << s << " ";
        for(int i = 1; i < size; ++i) {
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if(s[i] == s[j]) j++;
            pi[i] = j;
        }
        // fout << mx << endl;
        // fout << pi[size-1] << endl;
        if(pi[size-1] == 0) cout << x * size;
        else cout << size * x - pi[size-1] * (x - 1);
        if(n != 0) cout << endl;
    }
}

