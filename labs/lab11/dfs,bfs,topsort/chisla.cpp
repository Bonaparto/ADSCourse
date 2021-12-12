#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int st, end;
    vector <int> p(10000);
    p.assign(10000, -1);
    queue <int> q;
    fin >> st >> end;

    q.push(st);

    while(!q.empty()) {
        int next = q.front();
        q.pop();

        if(next == end) break;
        if(next % 10 > 1) {
            if(next - 1 > 1000 && p[next-1] == -1) {
                p[next - 1] = next;
                q.push(next - 1);
            }
        }
        if(next / 1000 != 9) {
            if(p[next + 1000] == -1) {
                p[next + 1000] = next;
                q.push(next + 1000);
            }
        }
        string temp = to_string(next);
        rotate(temp.begin(), temp.begin() + 1, temp.end());
        int temp1 = stoi(temp);

        if(temp1 > 1000 && p[temp1] == -1){ 
            p[temp1] = next;
            q.push(temp1);
        }
        temp = to_string(next);
        rotate(temp.begin(), temp.begin() + temp.length() - 1, temp.end());
        temp1 = stoi(temp);

        if(temp1 > 1000 && p[temp1] == -1) {
            p[temp1] = next;
            q.push(temp1);
        }
    }
    vector <int> ans;
    for(int i = end; i != st; i = p[i]) {
        ans.push_back(i);
    }
    ans.push_back(st);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i] << endl;
    }

}