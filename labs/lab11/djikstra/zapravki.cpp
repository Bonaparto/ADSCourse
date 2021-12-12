#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int,int> pii;

int main() {
    int n, m, inf = 200;
    fin >> n;
    int a[n];
    vector <vector<pii>> vv(n);
    bool used[n];
    int d[n];
    for(int i = 0; i < n; ++i) {
        fin >> a[i];
        used[i] = false;
        d[i] = inf;
    }

    fin >> m;
    for(int i = 0; i < m; ++i) {
        int x, y; fin >> x >> y;
        --x; --y;
        vv[x].push_back({y, a[y]});
        vv[y].push_back({x, a[x]});
    }

    d[0] = a[0];

    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!used[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        if(d[v] >= inf) break;
        used[v] = 1;
        for(int j = 0; j < vv[v].size(); ++j) {
            int u = vv[v][j].first;
            int w = vv[v][j].second;
            if(d[u] > d[v] + w) {
                d[u] = d[v] + w;
            }
        }
    }
    if(d[n-1] >= inf) fout << -1;
    else fout << d[n-1] - a[n-1];
}