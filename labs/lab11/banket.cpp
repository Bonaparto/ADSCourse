#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector <vector<int>> vv;
vector <int> color;
vector <int> partition;

bool bfs(int v) {
    partition[v] = 1;
    queue <int> q;
    q.push(v);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < vv[u].size(); ++i) {
            int next = vv[u][i];
            if(partition[next] == partition[u]) {
                return 0;
            }
            else if(partition[next] == 0){
                // if(color[next] == 0) {
                    color[next] = 1;
                    partition[next] = 3 - partition[u];
                    q.push(next);
                // }
            }
        }
    }
    color[v] = 2;
    return 1;
}

int main(){
    int n, m;
    fin >> n >> m;
    partition.assign(n, 0);
    color.assign(n, 0);
    vv.resize(n);
    for(int i = 0; i < m; ++i) {
        int x, y; fin >> x >> y;
        vv[--x].push_back(--y);
        vv[y].push_back(x);
    }   
    color[0] = 1;
    for(int i = 0; i < n; ++i) {
        if(partition[i] == 0){
            if(!bfs(i)) {
                fout << "NO";
                return 0;
            }
        } 
    }

    fout << "YES" << endl;
    for(int i = 0; i < n; ++i) {
        if(partition[i] == 1) 
        fout << i + 1 << " ";
    }

}
