#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> vv;
vector<int> cmp;
vector<bool> used;
int cnt = 0;

void dfs(int v) {
    used[v] = true;
    cmp.push_back(v + 1);
    for(int i = 0; i < vv[v].size(); ++i) {
        if(!used[vv[v][i]]) dfs(vv[v][i]);
    }
}

int main() {
    int n, m;
    fin >> n >> m;
    vv.resize(n);
    used.assign(n, false);
    for(int i = 0; i < m; ++i) {
        int x, y;
        fin >> x >> y;
        x--; y--;
        vv[x].push_back(y);
        vv[y].push_back(x);
    }

    vector<vector<int>> ans;

    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            dfs(i);
            cnt++;
            ans.push_back(cmp);
            cmp.clear();
        }
    }

    fout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i].size() << endl;
        for(int j = 0; j < ans[i].size(); ++j) {
            fout << ans[i][j] << " ";
        }
        fout << endl;
    }

}