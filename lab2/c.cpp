#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool string_cmp(string a, string b) {
    for(long long i = 0; i < min(a.size(), b.size()); ++i) {
        if(a[i] > b[i]) return 0;
        else if(a[i] < b[i]) return 1;
    }
    if(a.size() < b.size()) return 1;
    return 0;
}

bool cmp(pair <string, int> p1, pair <string, int> p2) {
    if(p1.second == p2.second) return string_cmp(p1.first, p2.first);
    return p1.second > p2.second;
}

void sort_map(map <string, int>& m) {
    vector <pair <string, int> > v;
    for(auto& it : m) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); ++i) fout << v[i].first << " " << v[i].second << endl;
}

int main(){
    map <string, int> mp;
    string s;
    while(fin >> s) {
        mp[s]++;
    }
    map <string, int> :: iterator it;
    sort_map(mp);
    // for(it = mp.begin(); it != mp.end(); ++it) fout << (*it).first << " " << (*it).second << endl;
}