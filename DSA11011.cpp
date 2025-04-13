// DSA11011 - CÂY NHỊ PHÂN ĐỦ

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree{
private:
    Node *root;
    void makeNode(Node *node, int value, char side){
        if(side == 'L'){
            node->left = new Node(value);
        }
        else if(side == 'R'){
            node->right = new Node(value);
        }
    }

    void _insertNode(Node *node, int parrent, int child, char side){
        if(node == nullptr)
            return;
        if(node->val == parrent){
            this->makeNode(node, child, side);
        }
        else{
            _insertNode(node->left, parrent, child, side);
            _insertNode(node->right, parrent, child, side);
        }
    }

public:
    Tree(){this->root = nullptr;};
    void setRoot(Node *node){
        this->root = node;
    }
    Node *getRoot(){
        return this->root;
    }

    void insertNode(int parrent, int child, char side){
        this->_insertNode(this->root, parrent, child, side);
    }
};

bool isFullTree(Node *treeRoot){
    if(treeRoot == nullptr)
        return true;
    if(treeRoot->left == nullptr && treeRoot->right == nullptr)
        return true;
    if(treeRoot->left == nullptr || treeRoot->right == nullptr)
        return false;
    if(treeRoot->left && treeRoot->right)
        return (isFullTree(treeRoot->left) && isFullTree(treeRoot->right));
}

void solve(){
    int n;
    cin >> n;
    Tree tree;
    while(n--){
        int parrent, child;
        char side;
        cin >> parrent >> child >> side;
        if(tree.getRoot() == nullptr){
            tree.setRoot(new Node(parrent));
        }
        tree.insertNode(parrent, child, side);
    }
    Node *t1 = tree.getRoot();
    cout << isFullTree(t1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
