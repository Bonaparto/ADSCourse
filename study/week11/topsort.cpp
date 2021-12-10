#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define N 100
int n;

vector<int> ans;
bool used[N];
int a[N][N];

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < n; ++i) {
        if(a[v][i] == 1 && !used[i]) dfs(i);
    }
    ans.push_back(v + 1);
}

int main() {
    fin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        if(!used[i]) dfs(i);
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i] << " ";
    }
}