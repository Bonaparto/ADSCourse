#include <fstream>
#include <set>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct vertex {
    int next[26], cnt;
    bool isEndOfWord;
};

set <string> words;
vertex t[1000000];
int sz = 1;

void init() {
    for(int i = 0; i < 26; ++i) {
        t[0].next[i] = -1;
    }
    t[0].cnt = 0;
}

void add_string(string s) {
    int v = 0;
    for(int i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if(t[v].next[c] == -1) {
            for(int j = 0; j < 26; ++j) {
                t[sz].next[j] = -1;
                t[sz].cnt = 0;   
            }
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
        t[v].cnt++;
    }
    t[v].isEndOfWord = true;
}

void delete_string(string s) {
    if(words.find(s) != words.end()) {
        int v = 0;
        for(int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if(t[v].next[c] == -1) return;
            v = t[v].next[c];
            t[v].cnt--;
        }
        t[v].isEndOfWord = false;
        words.erase(s);
    }
}

int cnt(string s) {
    int v = 0, c = 0;
    for(int i = 0; i < s.size(); ++i){
        int c = s[i] - 'a';
        if(t[v].next[c] == -1) return 0;
        v = t[v].next[c];
    }
    return t[v].cnt;
}

int main() {
    int n;
    fin >> n;
    init();
    for(int i = 0; i < n; ++i) {
        char c; string s;
        fin >> c >> s;
        if(c == '+') {
            add_string(s);
            words.insert(s);
            // fout << search(s) << " ";
        } else if(c == '-') {
            delete_string(s);
        } else {
            // fout << search(s) << " ";
            // fout << s << endl;
            fout << cnt(s) << endl;
        }
        // fout << i << ' ' << c << endl;
    }
}