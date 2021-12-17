#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 1e6;

typedef pair<int,int> pii;

int main() {
    int n, m;
    fin >> n >> m;
    long long pref[n+1];
    pref[0] = 0;
    for(int i = 0; i < n; ++i) {
        int x; fin >> x;
        pref[i+1] = pref[i] + x;
        fout << pref[i+1] << endl;
    }

}