#include<iostream>
using namespace std ;
// Definition for a binary tree node.
//this Q maze me confuse 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getMin(TreeNode* root) {
        if(!root) return 0;
        while(root->right){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int target) {
        if(!root) return NULL;
        if(root->val==target){
            //if 0 child to target Node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //if 1 child to target Node on left
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            //if 1 child to target Node on right
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            //if target node have 2 child
            if(root->left!=NULL && root->right!=NULL){
                int maxVal=getMin(root->left);
                root->val=maxVal;
                root->left=deleteNode(root->left,maxVal);
                return root;
            }
        }
        else{
            if(target<root->val) root->left=deleteNode(root->left,target);
            if(target>root->val) root->right=deleteNode(root->right,target);
        }
        return root;
    }
};

int main()
{
    return 0;
}