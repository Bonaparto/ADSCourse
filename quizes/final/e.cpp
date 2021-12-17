#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ifstream cin("input.txt");
// ofstream cout("output.txt");

const int N = 1e6;

typedef pair<int,int> pii;

vector<vector<int>> graph;
vector <bool> used;
vector <int> cmp;
map <int, int> mp;
map <int, vector<vector<int>> > ans;

void dfs(int v) {
    used[v] = true;
    cmp.push_back(v + 1);
    for(int i = 0; i < graph[v].size(); ++i) {
        if(!used[graph[v][i]]) dfs(graph[v][i]); 
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    used.assign(n, false);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        graph[--x].push_back(--y);
        graph[y].push_back(x);
        // cout << x << " " << endl;
    }
    // vector<vector<int>> ans;
    for(int i = 0; i < n; ++i) {
        // cout << i << endl;
        if(!used[i]) {
            dfs(i);
            if(cmp.size() > 3) {
                cout << -1;
                return 0;
            }
            mp[cmp.size()]++;
            ans[cmp.size()].push_back(cmp);
            // for(int i = 0; i < cmp.size(); ++i) {
            //     cout << cmp[i] << " " << i << endl;
            // }
            // cout << endl;
            cmp.clear();
        }
    }
    if((mp[1] + mp[2] * 2) % 3 != 0) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < ans[3].size(); ++i) {
        for(int j = 0; j < ans[3][i].size(); ++j) {
            cout << ans[3][i][j] << " ";
        } 
        cout << endl;
    }
    int i = 0;
    for(i = 0; i < ans[2].size(); ++i) {
        for(int j = 0; j < ans[2][i].size(); ++j) {
            cout << ans[2][i][j] << " ";
        }
        cout << ans[1][i][0] << endl;
    }
    int cnt = 0;
    for(int k = i; k < ans[1].size(); ++k) {
        cnt++;
        cout << ans[1][k][0];
        if(cnt % 3 == 0 && k != ans[1].size() - 1) cout << endl;
        else cout << " ";
    }
}