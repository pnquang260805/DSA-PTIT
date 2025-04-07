// DSA11008 - KIỂM TRA NODE LÁ

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
    void MakeNode(Node *node, int data, char side) {
        if (side == 'L') {
            if (node->left == nullptr)
                node->left = new Node(data);
        }
        else if (side == 'R') {
            if (node->right == nullptr)
                node->right = new Node(data);
        }
    }

    void InsertNode(Node *node, int parrent, int child, char side){
        if(node == nullptr)
            return;
        if(node->val == parrent){
            this->MakeNode(node, child, side);
        }
        else{
            this->InsertNode(node->left, parrent, child, side);
            this->InsertNode(node->right, parrent, child, side);
        }
    }

    int countLeaf(Node *node){
        if(node == nullptr)
            return 0;
        if(node->left == nullptr && node->right == nullptr)
            return 1;
        return this->countLeaf(node->left) +this->countLeaf(node->right);
    }
public:
    Tree(){
        this->root = nullptr;
    }
    void Insert(int parrent, int child, char side){
        this->InsertNode(this->root, parrent, child, side);
    }

    int CountLeafLeft(){
        return this->countLeaf(this->root->left);
    }

    int CountLeafRight(){
        return this->countLeaf(this->root->right);
    }


    Node *getRoot(){
        return this->root;
    }

    void setRoot(Node *node){
        this->root = node;
    }
};

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
        tree.Insert(parrent, child, side);
    }
    cout << (tree.CountLeafLeft() ==tree.CountLeafRight());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
