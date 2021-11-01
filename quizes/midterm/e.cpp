#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <int, int> mp;

struct node {
    int val;
    node * right;
    node * left;
    node(int x){
        val = x;
        right = NULL;
        left = NULL;
    } 
};

struct bst {
private : 

    node * root;

    node * add(node * current, int x){
        if(current == NULL) return new node(x);

        if(current->val > x) current->left = add(current->left, x);
        else if (current->val < x) current->right = add(current->right, x);

        return current;
    }

    void height(node * current) {
        node * temp = current;
        int l = 0, r = 0;
        while(temp != NULL) {
            temp = temp->left;
            l++;
        }
        temp = current;
        while(temp != NULL) {
            temp = temp->right;
            r++;
        } 
        for(int i = 1; i <= min(l, r); ++i) mp[i]++;
    }

    void count_height(node * current) {
        if(current != NULL) {
            count_height(current->left);
            count_height(current->right);
            height(current);
        }
    }

public:       

    bst() {
        root = NULL;
    }

    void add(int x) {
        node * res = add(root, x);
        if(root == NULL) root = res;
    }

    void count_height() {
        return count_height(root);
    }

};

int main(){
    int n;
    fin >> n;
    bst bs;
    for(int i = 0; i < n; ++i) {
        int x; fin >> x;
        bs.add(x);
    }
    bs.count_height();
    map <int, int> :: iterator it;
    for(int i = 2; i <= n; ++i) fout << mp[i] << " ";
}