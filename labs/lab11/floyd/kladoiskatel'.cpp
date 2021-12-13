#include <fstream>
#include <queue>
using namespace std;

// NE DODELAN

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair<int,int> pii;

char map[105][105];
int n;

int bfs(int x, int y) {
    int cnt = 0, i, j;
    queue<pii> q;
    q.push({x, y});
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        i = p.first, j = p.second;
        if(map[i][j] == '*') break;
        if(i + 1 < n && map[i+1][j] != '1') {
            q.push({i+1, j});
            map[i+1][j] = '1';
        }
        if(j + 1 < n && map[i][j+1] != '1') {
            q.push({i, j+1});
            map[i][j+1] = '1';
        }
        if(i - 1 >= 0 && map[i-1][j] != '1') {
            q.push({i-1, j});
            map[i-1][j] = '1';
        }
        if(j - 1 >= 0 && map[i][j-1] != '1') {
            q.push({i, j-1});
            map[i][j-1] = '1';
        }
        cnt++;
    }
    fout << i << " " << j <<  endl;
    if(map[i][j] == '*') return cnt;
    else return -1;
}

int main() {
    int m, ans = 1000;
    fin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            fin >> map[i][j];
        }
    }
    int l;
    fin >> l;
    for(int i = 0; i < l; ++i) {
        int x, y; fin >> x >> y;
        int cur = bfs(--x, --y);
        fout << cur << " " << x << " " << y << endl;
        if(cur != -1 && cur < ans) ans = cur;
        if(ans == 0) break;
    }
    if(ans == 1000) fout << -1;
    else fout << ans;
}