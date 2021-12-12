#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int N = 105;

vector <vector<int>> vv;
vector <bool> used;
vector <int> color;
vector <int> ans;

void dfs(int v) {
    used[v] = 1;
    for(int i = 0; i < vv[v].size(); ++i) {
        int next = vv[v][i];
        if(!used[next]) dfs(next);
    }
    ans.push_back(v);
}

bool has_cycle(int v) {
    color[v] = 1;
    for(int i = 0; i < vv[v].size(); ++i) {
        int next = vv[v][i];
        if(color[next] == 0) {
            if(has_cycle(next)) return true;
        }
        else if(color[next] == 1) return true;
    }
    color[v] = 2;
    return false;
}

int main(){
    int n, m;
    fin >> n >> m;
    vv.resize(n);
    used.resize(n);
    color.resize(n);
    for(int i = 0; i < n; ++i) {
        used[i] = color[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        int x, y;
        fin >> x >> y;
        vv[--x].push_back(--y);
    }

    for(int i = 0; i < n; ++i) {
        if(has_cycle(i)) {
            fout << "No";
            return 0;
        }
    }

    for(int i = 0; i < n; ++i) {
        if(!used[i]) dfs(i);
    }

    fout << "Yes" << endl;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i] + 1 << " ";
    }
}