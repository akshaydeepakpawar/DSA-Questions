#include<iostream>
using namespace std ;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int val){
        this->data=val;
        left=NULL,right=NULL;
    }
};


void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // NLR
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // LNR
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* currentNode=q.front();
            q.pop();
            cout<<currentNode->data<<" ";
            if(currentNode->left) q.push(currentNode->left);
            if(currentNode->right) q.push(currentNode->right);
        }
        cout<<endl;
    }
}



Node *buildBst(Node *root,int val){
    if(root==NULL) return new Node(val);
    if(root->data>val)  root->left=buildBst(root->left,val);
    if(root->data<val)  root->right=buildBst(root->right,val);
    return root;
}

void createBST(Node* &root){
    cout<<"enter the values for nodes: "<<endl;
    while(true){
        int val;
        cin >> val;
        if (val == -1) break;
        root=buildBst(root,val);
    }
}

int main()
{
    Node* root=NULL;
    createBST(root);
    cout << "preorder Traversal : " << endl;
    preorderTraversal(root);
    cout<<endl;
    cout << "inorder Traversal : " << endl;
    inorderTraversal(root);
    cout<<endl;
    cout << "postorder Traversal : " << endl;
    postorderTraversal(root);
    cout<<endl;
    cout << "levelorder Traversal : " << endl;
    levelOrderTraversal(root);
    return 0;
}