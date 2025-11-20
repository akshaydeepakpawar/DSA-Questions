#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->data = x;
        left = NULL;
        right = NULL;
    }
};

Node *createNode()
{
    // cout << "enter the value of the node : " << endl;
    int value;
    cin >> value;
    if (value == -1)
        return NULL;
    else
    {
        // valid value here so create new node;
        Node *root = new Node(value);
        // 1 case me handle kar lunga baki recc handle kar lega
        // cout << "adding left child for value : " << value << endl;
        root->left = createNode();
        // cout << "adding right child for value : " << value << endl;
        root->right = createNode();
        return root;
    }
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // NLR
    cout << root->data << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // LNR
    inorderTraversal(root->left);
    cout << root->data << endl;
    inorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << endl;
}

void levelorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data<<" ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

int main()
{
    // i/p : 10 50 40 -1 -1 -1 30 20 -1 -1 -1
    Node *root;
    root = createNode();
    // cout << "printing root node : " << root->data << endl;
    cout << "preorder Traversal : " << endl;
    preorderTraversal(root);
    cout << "inorder Traversal : " << endl;
    inorderTraversal(root);
    cout << "postorder Traversal : " << endl;
    postorderTraversal(root);
    cout << "levelorder Traversal : " << endl;
    levelorderTraversal(root);
    return 0;
}