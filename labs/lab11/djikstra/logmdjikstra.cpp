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
    priority_queue <int> pq;
    fin >> n >> m;
    vector<vector<pii>> graph(n);
    long long d[n];

    for(int i = 0; i < m; ++i) {
        int x, y, w;
        fin >> x >> y >> w;
        graph[x].push_back({y, w});  
        graph[y].push_back({x, w});      
    }

    for(int i = 0; i < n; ++i) {
        d[i] = inf;
    } 

    int st;
    fin >> st;

    d[st] = 0;
    set<pii> s;
    s.insert({0, st});

    while(!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for(pii p : graph[v]) {
            int u = p.first;
            int w = p.second;
            if(d[v] + w < d[u]) {
                s.erase({d[u], u});
                d[u] = d[v] + w;
                s.insert({d[u], u});
            }
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