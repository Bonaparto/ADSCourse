#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 105;

vector <vector<int>> vv;

void bfs(int st, int end) {
    int sz = vv.size(), inf = 1001;
    queue <int> q;
    vector <bool> used(sz);
    vector <int> p(sz);
    vector <int> d(sz);
    d.assign(sz, inf);
    used.assign(sz, 0);
    used[st] = 1;
    p[st] = -1;
    q.push(st);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < vv[u].size(); ++i) {
            int next = vv[u][i];
            if(!used[next]) {
                used[next] = true;
                d[next] = d[u] + 1;
                p[next] = u;
                q.push(next);
            }
        }
    }

    if(!used[end]) {
        fout << -1;
        return;
    }

    vector <int> ans;
    for(int v = end; v != st; v = p[v]) {
        ans.push_back(v);
    }
    fout << ans.size() << endl;
    ans.push_back(st);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i] + 1 << " ";
    }
}

int main() {
    int n, x, y;
    fin >> n;
    vv.resize(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> x;
            if(x == 1) {
                vv[i].push_back(j);
                vv[j].push_back(i);
            }
        }
    }
    fin >> x >> y;
    if(x == y) {
        fout << 0;
        return 0;   
    }
    bfs(--x, --y);
}