#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define N 100005

bool used[N];
vector<vector<int>> vv(N);
vector <int> ans;
vector <int> v1(N);

void dfs(int v) { 
    used[v] = true;
    // fout << v << " in" << endl;
    for(int i = 0; i < vv[v].size(); ++i) {
        int next = vv[v][i];
        if(!used[next]) dfs(next);
    }
    // fout << v << " out" << endl;
    ans.push_back(v);
}

bool is_cyclic(int v) {
    v1[v] = 1;
    for(int i = 0; i < vv[v].size(); ++i) {
        int next = vv[v][i];
        if(v1[next] == 0) {
            if(is_cyclic(next)) return true;
        }
        else if(v1[next] == 1) return true;
    }
    v1[v] = 2;
    return false;
}

int main(){
    int n, m;
    fin >> n >> m;
    for(int i = 0; i < n; ++i) {
        used[i] = false;
        v1[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        int x, y;
        fin >> x >> y;
        vv[--x].push_back(--y);
    }
    for(int i = 0; i < n; ++i) {
        if(is_cyclic(i)) {
            fout << "Impossible";
            return 0;
        }
    }
    fout << "Possible" << endl;
    for(int i = 0; i < n; ++i) {
        if(!used[i]) dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) fout << ans[i] + 1 << " ";  
}