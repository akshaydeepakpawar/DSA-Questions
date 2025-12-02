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
    else{
        if(root->data>val){
            root->left=buildBst(root->left,val);
        }
        if(root->data<val){
            root->right=buildBst(root->right,val);
        }
    }
    return root;
}

void createBST(Node* &root){
    cout<<"enter the values for nodes: "<<endl;
    int val;
    cin>>val;
   while(val!=-1){
        root=buildBst(root,val);
        cin>>val;
   }
}

int main()
{
    Node* root=NULL;
    createBST(root);
    levelOrderTraversal(root);
    return 0;
}