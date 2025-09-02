// Online C++ compiler to run C++ program online
//input is compleet binary tree
#include <iostream>
using namespace std;
#include <queue>

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int data){
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
    
};

Node* create(){
    cout<<"enter calue of node"<<endl;
    int data;
    cin>>data;
    
    if(data==-1) return NULL;
    
    Node* root =new Node(data);
    cout<<"create left of "<<data<<endl;
    root->left= create();
    cout<<"create right of "<<data<<endl;
    root->right=create();
    return root;
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();  // number of nodes in current level
        while (size--) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";   // print node
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // print new line after each level
    }
}

bool checkHeap(Node* root){
    if (root==NULL) return true;
    
    bool leftAns= checkHeap(root->left);
    bool rightAns= checkHeap(root->right);
       if (root->left && !root->right) {
        return (root->val > root->left->val) && leftAns;
    }

    // Case: leaf node
    if (!root->left && !root->right) return true;
    
    if(root->left && root->right){
    if (root->val>root->left->val && root->val>root->right->val && leftAns && rightAns){ return true;
    }}
    return false;
}

int main(){
    Node* root=create();
    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);
    checkHeap(root) ? cout<<" is heap": cout<<" not heap"<<endl;
}
