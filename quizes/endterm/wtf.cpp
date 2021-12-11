#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<pair<int, int>> graph[505050];
int dist[505050], pr[505050];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int v, u, c;
        cin >> v >> u >> c;
        graph[v].push_back(make_pair(u, c));
        graph[u].push_back(make_pair(v, c));
    }
    int start, merch, pharm, finish, ans = 0;
    cin >> start >> merch >> pharm >> finish;
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pr[start] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        int dst = cur.first, v = cur.second;
        if (dist[v] < dst) continue;
        for (pair<int, int> e: graph[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < dist[u]) {
                pr[u] = e.first;
                dist[u] = n_dst;
                q.push({n_dst, u});
            }
        }
        if (cur.second == merch || cur.second == pharm) break;
    }
    if (dist[merch] < dist[pharm]) {
        if (dist[merch] == INF) {
            cout << "-1";
            return 0;
        }
        ans += dist[merch];
        while(!q.empty()) q.pop();
        for (int i = 1; i <= n; ++i) {
            dist[i] = INF;
        }
        dist[merch] = 0;
        q.push({0, merch});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            int dst = cur.first, v = cur.second;
            if (dist[v] < dst) continue;
            for (pair<int, int> e: graph[v]) {
                int u = e.first, len_vu = e.second;
    
                int n_dst = dst + len_vu;
                if (n_dst < dist[u]) {
                    pr[u] = e.first;
                    dist[u] = n_dst;
                    q.push({n_dst, u});
                }
            }
            if (cur.second == pharm) break;
        }
        if (dist[pharm] == INF) {
            cout << "-1";
            return 0;
        }
        ans += dist[pharm];
        while(!q.empty()) q.pop();
        for (int i = 1; i <= n; ++i) {
            dist[i] = INF;
        }
        dist[pharm] = 0;
        q.push({0, pharm});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            int dst = cur.first, v = cur.second;
            if (dist[v] < dst) continue;
            for (pair<int, int> e: graph[v]) {
                int u = e.first, len_vu = e.second;
        
                int n_dst = dst + len_vu;
                if (n_dst < dist[u]) {
                    pr[u] = e.first;
                    dist[u] = n_dst;
                    q.push({n_dst, u});
                }
            }
            if (cur.second == finish) break;
        }
        if (dist[finish] == INF) {
            cout << "-1";
            return 0;
        }
        ans += dist[finish];
    } else {
        if (dist[pharm] == INF) {
            cout << "-1";
            return 0;
        }
        ans += dist[pharm];
        while(!q.empty()) q.pop();
        for (int i = 1; i <= n; ++i) {
            dist[i] = INF;
        }
        dist[pharm] = 0;
        q.push({0, pharm});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            int dst = cur.first, v = cur.second;
            if (dist[v] < dst) continue;
            for (pair<int, int> e: graph[v]) {
                int u = e.first, len_vu = e.second;
    
                int n_dst = dst + len_vu;
                if (n_dst < dist[u]) {
                    pr[u] = e.first;
                    dist[u] = n_dst;
                    q.push({n_dst, u});
                }
            }
            if (cur.second == merch) break;
        }
        if (dist[merch] == INF) {
            cout << "-1";
            return 0;
        }
        ans += dist[merch];
        while(!q.empty()) q.pop();
        for (int i = 1; i <= n; ++i) {
            dist[i] = INF;
        }
        dist[merch] = 0;
        q.push({0, merch});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            int dst = cur.first, v = cur.second;
            if (dist[v] < dst) continue;
            for (pair<int, int> e: graph[v]) {
                int u = e.first, len_vu = e.second;
        
                int n_dst = dst + len_vu;
                if (n_dst < dist[u]) {
                    pr[u] = e.first;
                    dist[u] = n_dst;
                    q.push({n_dst, u});
                }
            }
            if (cur.second == finish) break;
        }
        if (dist[finish] == INF) {
            cout << "-1";
            return 0;
        }
        ans += dist[finish];
    }
    cout << ans;

    return 0;
}
