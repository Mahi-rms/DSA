#include<bits/stdc++.h>
using namespace std;
struct BTNode{
    BTNode* left;
    int val;
    BTNode* right;
};
BTNode* head=NULL;
BTNode* getNode(int val){
    BTNode* node=new BTNode();
    node->left=NULL;
    node->val=val;
    node->right=NULL;
    return node;
}
BTNode* attach(BTNode* node,BTNode* root){
    if(root==NULL){
        root=node;
        return root;
    }
    if(node->val<=root->val) root->left=attach(node,root->left);
    else root->right=attach(node,root->right);
    return root;
}
BTNode* insert(int val,BTNode* root){
    BTNode* node=getNode(val);
    return attach(node,root);
}
void preOrder(BTNode* root){
    if(root==NULL) return;
    cout<<root->val<<"(*)";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(BTNode* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->val<<"(*)";
    inOrder(root->right);
}
void postOrder(BTNode* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<"(*)";
}
int main(){
    int n;
    cin>>n;
    BTNode* root=NULL;
    head=NULL;
    while(n--){
        int p;
        cin>>p;
        root=insert(p,root);
    }
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
}