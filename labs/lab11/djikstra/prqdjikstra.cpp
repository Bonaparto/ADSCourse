#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int,int> pii;

void solve() {
    int n, m;
    long long inf = 2009000999;
    fin >> n >> m;
    vector<vector<pii>> graph(n);
    long long d[n];
    bool used[n];

    for(int i = 0; i < m; ++i) {
        int x, y, w;
        fin >> x >> y >> w;
        graph[x].push_back({y, w});  
        graph[y].push_back({x, w});      
    }

    for(int i = 0; i < n; ++i) {
        used[i] = false;
        d[i] = inf;
    } 

    int st;
    fin >> st;

    d[st] = 0;
    priority_queue <pii> pq;
    pq.push({0, st});

    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        used[v] = true;
        for(pii p : graph[v]) {
            int u = p.first;
            if(used[u]) continue;
            int w = p.second;
            if(d[v] + w < d[u]) {
                d[u] = d[v] + w;
                pq.push({d[u], u});
            }
            used[u] = true;
        }
    }
    for(int i = 0; i < n; ++i) {
        fout << d[i] << " ";
    }
    fout << endl;
}
 
int main() { 
    int n;
    fin >> n;
    while(n--) {
        solve();
    }
}