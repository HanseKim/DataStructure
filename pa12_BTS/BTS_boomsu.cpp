#include <iostream>
#include <vector>
#define print_ans for (auto v : vec) {cout << v << " ";} cout << endl
#define tn TreeNode *

using namespace std;
vector<string> vec;

typedef struct _TreeNode{
    string key;
    _TreeNode *left;
    _TreeNode *right;     
}TreeNode;

void s(tn n, int d, int c) {
    if (n == NULL) return;
    if (c == d) vec.push_back(n->key);
    if (n->left == NULL && n->right == NULL && d < 0) {
        vec.push_back(n->key);
    }
    s(n->left, d, c+1);
    s(n->right, d, c+1);
}

tn cN(string k) {
    tn root = new TreeNode;
    root->key = k;
    root->left = root->right = NULL;
    return root;
}

tn ins(tn node, string key) {
    if (node == NULL) {
        node = cN(key);
        return node;
    }
    if (node->key < key) node->right = ins(node->right, key);
    else if (node->key > key) node->left = ins(node->left, key);
    return node;
}

tn maxn(tn node) {
    if (node == NULL) return NULL;
    tn current = node;
    while (current->right != NULL)current = current->right;
    return current;
}

tn minn(tn node) {
    tn current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

tn dn(tn parent, tn root, string key){
    if (root == NULL) return root;
    if (root->key < key) dn(root, root->right, key);
    else if (root->key > key) dn(root, root->left, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            if (parent == NULL) {
                return NULL;
            }
            else {
                if (parent->left == root) parent->left = NULL;
                if (parent->right == root) parent->right = NULL;
                return parent;
            }
        }
        else {
            if (root->right == NULL) {
                tn del = maxn(root->left);
                root->key = del->key;
                dn(root, root->left, del->key);
                dn(root, root->right, del->key);
            }
            else{
                tn del = minn(root->right);
                root->key = del->key;
                dn(root, root->left, del->key);
                dn(root, root->right, del->key);
            }
        }
    }
    return root;
}

int main(){
    tn root = NULL;
    int num;
    cin >> num;
    while(num--){
        string name, op;
        int k;
        cin >> op;
        if (op == "leaf") {
            s(root, -1, 1);
            print_ans;
        }
        else if (op == "depth") {
            cin >> k;
            s(root, k, 1);
            if (vec.empty()) cout << "NO";
            print_ans;
        }
        else {
            cin >> name;
            if (op == "+") root = ins(root, name);
            else root = dn(NULL, root, name);
        }
        vec.clear();
    }
}