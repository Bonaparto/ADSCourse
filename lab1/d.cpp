#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct list {
    long long grade;
    string surname;
};

bool sort_by_grade(list a, list b) {
    return a.grade < b.grade;
}

int main(){
    vector <list> v;
    list l;
    long long n; string s;
    while(cin >> n) {
        cin >> s;
        l.grade = n;
        l.surname = s;
        v.push_back(l);
    }
    sort(v.begin(), v.end(), sort_by_grade);
    for(int i = 0; i < v.size(); ++i) cout << v[i].grade << " " << v[i].surname << endl;
}