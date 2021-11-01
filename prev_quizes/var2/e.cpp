#include <iostream>
using namespace std;

int cnt = 0;

struct node {
    int val;
    node * left;
    node * right;
    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst {

    node * root;

    bst() {
        root = NULL;
    }

    node * add(node * current, int x) {
        if(current == NULL) return new node(x);

        if(current->val > x) current->left = add(current->left, x);
        else if(current->val < x) current->right = add(current->right, x);

        return current;
    }

    void add(int x) {
        node * res = add(root, x);
        if(root == NULL) root = res;
    }

    void count_branches(node * current) {
        if(current != NULL) {
            count_branches(current->left);
            if(current->left != NULL && current->right != NULL) {
                cnt++;
            }
            count_branches(current->right);
        }
    }
    
    void count_branches() {
        count_branches(root);
    }

};

int main(){
    int n;
    cin >> n;
    bst b;
    while(n--) {
        int x; cin >> x;
        b.add(x);
    }
    b.count_branches();
    cout << cnt;
}