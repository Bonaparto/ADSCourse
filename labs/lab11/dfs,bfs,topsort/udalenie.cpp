#include <fstream>
#include <queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

char a[105][105];
int n, m;

void dfs(int x, int y) {
    a[x][y] = '.';
    if(x + 1 < m && a[x+1][y] == '#') dfs(x + 1, y);
    if(x - 1 >= 0 && a[x-1][y] == '#') dfs(x - 1, y);
    if(y + 1 < n && a[x][y+1] == '#') dfs(x, y + 1);
    if(y - 1 >= 0 && a[x][y-1] == '#') dfs(x, y - 1);
}

int main() {
    int ans = 0;
    fin >> m >> n;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> a[i][j];
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] == '#') {
                // fout << i << " " << j << endl;
                ans++;
                dfs(i, j);
            }
        }
    }
    fout << ans;
}