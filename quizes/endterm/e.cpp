#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define N 100005

bool used[N];
vector<vector<int>> vv(N);
vector <int> ans;
vector <int> v1(N);

int main(){
    int n, m;
    fin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y; fin >> x >> y;
        vv[--x].push_back(--y);
    }

}