#include <bits/stdc++.h>

using namespace std;

vector<int> graph[505050], graph1[505050];
bool used[505050], a[505][505];
int dst[505050], dst1[505050];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
        a[v][u] = 1;
        a[u][v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && !a[i][j]) {
                graph1[i].push_back(j);
                graph1[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {   
        dst[i] = -1;
        dst1[i] = -1;
    }
    queue<int> q, w;
    q.push(1);
    used[1] = true;
    dst[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : graph[cur]) {
            if (!used[to]) {
                q.push(to);
                used[to] = true;
                dst[to] = dst[cur] + 1;   
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
    }
    w.push(1);
    used[1] = true;
    dst1[1] = 0;
    while (!w.empty()) {
        int cur = w.front();
        w.pop();
        for (int to : graph1[cur]) {
            if (!used[to]) {
                w.push(to);
                used[to] = true;
                dst1[to] = dst1[cur] + 1;   
            }
        }
    }
    if (dst[n] == -1 || dst1[n] == -1) 
        cout << -1;
    else cout << max(dst[n], dst1[n]);
    return 0;
}