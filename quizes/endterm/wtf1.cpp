#include <bits/stdc++.h>

using namespace std;

vector<int> graph[505050], ans;
bool used[505050];
int cl[505050], color, ent[505050];

void dfs(int v, int p = -1) {   
    used[v] = true;
    ans.push_back(v);
    for (int u: graph[v]) {
        if (!used[u]) {
            cl[u] = color;
            dfs(u, v);
        } else if (cl[u] == -1) {
            cout << "Impossible";
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        ent[u]++;
    }
    for (int i = 1; i <= n; i++) {
        cl[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if(!ent[i] && !used[i]) {
            color++;
            dfs(i);
        }
    }

    if (ans.size() != n) {
        cout << "Impossible";
    } else {
        cout << "Possible\n";
        for (int it : ans) {
            cout << it << " ";
        }
    }
}
