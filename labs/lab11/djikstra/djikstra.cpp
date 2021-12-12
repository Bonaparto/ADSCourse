#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int, int> pii;

int main(){
    int n, st, end;
    int inf = 400;
    fin >> n >> st >> end;
    vector<vector<pii>> graph(n);
    vector<int> d(n);   
    vector<bool> used(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; fin >> x;
            if(x != -1) {
                graph[i].push_back({j, x});
            }
        }
    }

    d.assign(n, inf);
    used.assign(n, false);
    d[--st] = 0;

    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!used[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        if(d[v] >= inf) break;
        used[v] = true;
        for(int i = 0; i < graph[v].size(); ++i) {
            int u = graph[v][i].first;
            int w = graph[v][i].second;
            d[u] = min(d[u], d[v] + w);
        }
    } 
    --end;
    if(d[end] >= inf) fout << -1;
    else fout << d[end];
}