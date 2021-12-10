#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define N 100005

vector <vector<pair<int,int> > > vv(N);
bool used[6][N];
int d[6][N];
int inf = INT_MAX / 2;

int shortest_path(int p1, int n) {
    for(int i = 0; i < vv[p1].size(); ++i) {
        int v = -1;
        for(int j = 0; j < vv[p1].size(); ++j) {
            if(!used[n][vv[p1][j].first]) {
                if(v == -1 || d[n][v] > d[n][vv[p1][j].first]) {
                    v = vv[p1][j].first;
                }
            }
        }
        if(d[n][v] >= inf) break;
        used[n][v] = true;
        for(int j = 0; j < vv[p1].size(); ++j) {
            d[n][j] = min(d[n][vv[p1][j].first], d[n][v] + vv[p1][])
        }
    }
}

int main(){
    int n, m;

    fin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y, w; fin >> x >> y >> w;
        vv[--x].push_back(make_pair(--y, w));
    }

    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < n; ++j) {
            used[i][j] = false;
            d[i][j] = inf;
        }
    }

    int s, a, b, f;
    fin >> s >> a >> b >> f;
    d[0][s] = 0;
    d[1][a] = 0;
    d[2][b] = 0;
    d[3][f] = 0;
    for(int k = 0; k < 6; ++k) {
        for(int i = 0; i < n; ++i) {
            int v = -1;
        }
    }
}