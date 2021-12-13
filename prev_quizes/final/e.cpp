#include <fstream>
#include <vector> 
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<long long, long long> pii;

int main() {
    int n;
    fin >> n;
    vector <vector <pii>> graph(n);
    vector <pii> p(n);
    long long d[n], inf = 1e17;
    bool used[n];
    for(int i = 0; i < n; ++i) {
        int x, y; fin >> x >> y;
        used[i] = false;
        p[i] = {x, y};
        d[i] = inf;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            long long age = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
            graph[i].push_back({j, age});
        }
    }
    d[0] = 0;
    for(int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if(!used[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        used[v] = true;
        for(int j = 1; j < graph[v].size(); ++j) {
            int u = graph[v][j].first;
            int w = graph[v][j].second;
            if(w < d[v]) w = d[v];
            if(d[u] > w) {
                d[u] = w;
            }
        }
    }
    fout << d[n-1];
}