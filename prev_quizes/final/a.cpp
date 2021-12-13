#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    string s;
    fin >> s;
    int n = s.size();
    vector <int> pi(n);
    for(int i = 1; i < n; ++i) {
        int j = pi[j-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    } 
    for(int i = 1; i < n; ++i) {
        if(pi[i] < pi[i-1]) {
            int j = i;
        }
    }
}