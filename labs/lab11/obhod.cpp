#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int a[105][105];
bool used[105];
int n;

int dfs(int ans, int v) {
    used[v] = true;
    for(int i = 0; i < n; ++i) {
        if(!used[i] && a[v][i] == 1) {
            ans++;
            ans += dfs(0, i);
        }
    }
    return ans;
}

int main(){
    int m, ans = 1;
    fin >> n >> m;
    for(int i = 0; i < n; ++i) {
        used[i] = false;
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
        }
    } 
    for(int j = 0; j < n; ++j) {
        if(!used[j] && a[m-1][j] == 1) {
            ans += dfs(0, j); 
        }
    }
    fout << ans;
}   