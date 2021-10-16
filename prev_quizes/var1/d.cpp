#include <fstream>
#include <map>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int n, m;
    fin >> n >> m;
    map <int, int> mp, mp1;
    int cnt1 = 0, cnt2 = 0, ans1, ans2;
    for(int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        mp[max(x1, x2)]++;
        mp1[max(y1, y2)]++;
    }
    map <int, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); ++it) {
        fout << "mp1: " << (*it).first << " " << (*it).second << endl;
        cnt1 += (*it).second;
        if(cnt1 >= m) {
            ans1 = (*it).first;
            break;
        }
    }
    fout << endl;
    for(it = mp1.begin(); it != mp1.end(); ++it) {
        fout << "mp2: " << (*it).first << " " << (*it).second << endl;
        cnt2 += (*it).second; 
        if(cnt2 >= m) {
            ans2 = (*it).first;
            break;
        }
    }
    fout << max(ans1, ans2);
}