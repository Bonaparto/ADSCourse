#include <iostream>
using namespace std;

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

    void is_balanced(node * current, int l, int r) {
        if(current != NULL) {
            is_balanced(current->left);
            if((current->left != NULL && current->right == NULL) || 
            (current->left == NULL && current->right != NULL)) {
                cout << current->val << " ";
            }
            is_balanced(current->right);
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

    bool is_balanced() {
        is_balanced(root, 0, 0);
    }
};


int main(){
    int n;
    cin >> n;
    bst b;
    while(n != 0) {
        b.add(n);
        cin >> n;
    }
    cout << (b.is_balanced() ? "YES":"NO");
}