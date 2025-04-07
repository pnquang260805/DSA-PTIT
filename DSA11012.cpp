// DSA11012 - CÂY NHỊ PHÂN BẰNG NHAU

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

bool sameTree(Node *t1, Node *t2){
    if(t1 == nullptr && t2 == nullptr)
        return true;
    if(t1 == nullptr || t2 == nullptr|| t1->val != t2->val)
        return false;
    return sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);
}

void solve(){
    int n;
    cin >> n;
    Tree tree1, tree2;
    while(n--){
        int parrent, child;
        char side;
        cin >> parrent >> child >> side;
        if(tree1.getRoot() == nullptr){
            tree1.setRoot(new Node(parrent));
        }
        tree1.insertNode(parrent, child, side);
    }
    cin >> n;
    while(n--){
        int parrent, child;
        char side;
        cin >> parrent >> child >> side;
        if(tree2.getRoot() == nullptr){
            tree2.setRoot(new Node(parrent));
        }
        tree2.insertNode(parrent, child, side);
    }
    Node *t1 = tree1.getRoot();
    Node *t2 = tree2.getRoot();
    cout << sameTree(t1, t2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
