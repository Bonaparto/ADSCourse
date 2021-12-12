#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;

void bfs(pair<int, int> st, pair<int, int> end) {
    queue <pair<int, int>> q;
    map <pair<int,int>, pair<int,int> > p;
    pair <int,int> unk = {-1, -1};
    q.push(st);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            p[{i, j}] = unk;
        } 
    } 
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        if(u == end) break;
        if(u.first + 2 < n && u.second + 1 < n) {
            if(p[{u.first + 2, u.second + 1}] == unk) {
            q.push({u.first + 2, u.second + 1});
            p[{u.first + 2, u.second + 1}] = u;
            }
        }
        if(u.first + 2 < n && u.second - 1 >= 0) {
            if(p[{u.first + 2, u.second - 1}] == unk){
                q.push({u.first + 2, u.second - 1});
                p[{u.first + 2, u.second - 1}] = u;
            }
        }
        if(u.first - 2 >= 0 && u.second + 1 < n) {
            if(p[{u.first - 2, u.second + 1}] == unk){
                q.push({u.first - 2, u.second + 1});
                p[{u.first - 2, u.second + 1}] = u;
            }
        }

        if(u.first - 2 >= 0 && u.second - 1 >= 0) {
            if(p[{u.first - 2, u.second - 1}] == unk){
                q.push({u.first - 2, u.second - 1});
                p[{u.first - 2, u.second - 1}] = u;
            }
        }

        if(u.second + 2 < n && u.first + 1 < n) {
            if(p[{u.first + 1, u.second + 2}] == unk){
                q.push({u.first + 1, u.second + 2});
                p[{u.first + 1, u.second + 2}] = u;
            }
        }

        if(u.second + 2 < n && u.first - 1 >= 0) {
            if(p[{u.first - 1, u.second + 2}] == unk){
                q.push({u.first - 1, u.second + 2});
                p[{u.first - 1, u.second + 2}] = u;
            }
        }

        if(u.second - 2 >= 0 && u.first + 1 < n) {
            if(p[{u.first + 1, u.second - 2}] == unk){
                q.push({u.first + 1, u.second - 2});
                p[{u.first + 1, u.second - 2}] = u;
            }
        }

        if(u.second - 2 >= 0 && u.first - 1 >= 0) {
            if(p[{u.first - 1, u.second - 2}] == unk){
                q.push({u.first - 1, u.second - 2});
                p[{u.first - 1, u.second - 2}] = u;
            }
        }
    }
    vector <pair<int,int>> ans;
    for(pair<int,int> pr = end; pr != st; pr = p[pr]) {
        ans.push_back(pr);
    }
    fout << ans.size() << endl;
    ans.push_back(st);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }
}

int main(){
    int x, y, x1, y1;
    fin >> n >> x >> y >> x1 >> y1;
    bfs({--x, --y}, {--x1, --y1});    
}