#include <fstream>
using namespace std;

ifstream fin("inputik.txt");
ofstream fout("outputik.txt");

const int N = 1e6 + 5;

struct vertex{
    int next[26];
    int go[26];
    int p;
    int link;
    bool isEndOfWord;
    char pch;
};

vertex t[N];
int sz = 1;

void init() {
    t[0].p = t[0].link = 0;
    for(int i = 0; i < 26; ++i) {
        t[0].next[i] = -1;
        t[0].go[i] = -1;
    }
}

void add_string(string s) {
    int v = 0;
    for(int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        if(t[v].next[c] == -1) {
            for(int j = 0; j < 26; ++j) {
                t[sz].next[j] = -1;
                t[sz].go[j] = -1;
            }
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[c] = sz++;
        } 
        v = t[v].next[c];
    }
    t[v].isEndOfWord = true;
}

int get_link(int v) {
    if(t[v].link == -1) {
        if(v == 0 || t[v].p == 0) t[v].link = 0;
        else t[v].link = go(get_link(t[v].p), t[v].pch); 
    }
}

int go(int v, char c) {
    if(t[v].go[c] == -1) {
        if(t[v].next[c] != -1) {
            t[v].go[c] = t[v].next[c];
        } else t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
    }
    return t[v].go[c];
}

int main(){
   string text;
   int n;
   fin >> text >> n;
   while(n--) {
       string s;
       fin >> s;
       add_string(s);
    }
}