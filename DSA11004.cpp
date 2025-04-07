// DSA11004 - DUYỆT CÂY THEO MỨC
// BFS

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left, * right;
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree{
private:
    Node *root;

    void makeNode(Node *node, int data, char side){
        if(side == 'L'){
            if(node->left == nullptr)
                node->left = new Node(data);
        }
        else if(side == 'R'){
            if(node->right == nullptr)
                node->right = new Node(data);
        }
    }

    void insertNode(Node *node, int parrent, int child, char side){
        if(node == nullptr)
            return;
        if(node->val == parrent){
            this->makeNode(node, child, side);
        }
        else{
            this->insertNode(node->left, parrent, child, side);
            this->insertNode(node->right, parrent, child, side);
        }
    }
public:
    Tree(){
        this->root = nullptr;
    }

    Node *getRoot(){
        return this->root;
    }

    void setRoot(Node *node){
        this->root = node;
    }

    void insertNodeToTree(int parrent, int child, char side){
        insertNode(this->root, parrent, child, side);
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
        tree.insertNodeToTree(parrent, child, side);
    }
    queue<Node*> q;
    vector<int> ans;

    // BFS
    q.push(tree.getRoot());
    ans.push_back(tree.getRoot()->val);
    while(!q.empty()){
        Node *f = q.front();
        q.pop();
        if(f->left != nullptr){
            q.push(f->left);
            ans.push_back(f->left->val);
        }
        if(f->right != nullptr){
            q.push(f->right);
            ans.push_back(f->right->val);
        }
    }
    for(int i : ans)
        cout << i << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
