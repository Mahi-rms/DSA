#include<bits/stdc++.h>
using namespace std;
int pos=0;
struct BTNode{
    BTNode* left;
    int val;
    BTNode* right;
};
struct Node{
    BTNode* addr;
    Node* next;
};
Node* head=NULL;
BTNode* getNode(int val){
    BTNode* node=new BTNode();
    node->left=NULL;
    node->val=val;
    node->right=NULL;
    return node;
}
BTNode* buildBST_Pre(int start, int end,vector<int> preO,vector<int> inO,BTNode* root){
    if(start>end) return root;
    int index=find(inO.begin(),inO.end(),preO[pos])-inO.begin();
    root=getNode(preO[pos++]);
    root->left=buildBST_Pre(start,index-1,preO,inO,root->left);
    root->right=buildBST_Pre(index+1,end,preO,inO,root->right);
    return root;
}

BTNode* buildBST_Post(int start, int end,vector<int> postO,vector<int> inO,BTNode* root){
    if(start>end) return root;
    int index=find(inO.begin(),inO.end(),postO[pos])-inO.begin();
    root=getNode(postO[pos++]);
    root->right=buildBST_Post(index+1,end,postO,inO,root->right);
    root->left=buildBST_Post(start,index-1,postO,inO,root->left);
    return root;
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
void addAddrToStack(BTNode* ptr){
    if(ptr==NULL) return;
    Node* temp=new Node();
    temp->addr=ptr;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    Node* t=head;
    while(t->next) t=t->next;
    t->next=temp;
}
void levelOrder(BTNode* root){
    addAddrToStack(root->left);
    addAddrToStack(root->right);
    cout<<root->val<<"(*)";
    Node* temp=head;
    head=head->next;
    delete temp;
    if(head) levelOrder(head->addr);
    return;
}
void rightView(BTNode* root){
    if(root==NULL) return;
    queue<BTNode*> st;
    st.push(root);
    while(!st.empty()){
        int n=st.size();
        for(int i=0;i<n;i++){
            if(i==n-1) cout<<st.front()->val<<"(*)";
            BTNode* ptr=st.front();
            if(ptr->left) st.push(ptr->left);
            if(ptr->right) st.push(ptr->right);
            st.pop();
        }
    }
}
void leftView(BTNode* root){
    if(root==NULL) return;
    queue<BTNode*> st;
    st.push(root);
    while(!st.empty()){
        int n=st.size();
        for(int i=0;i<n;i++){
            if(i==0) cout<<st.front()->val<<"(*)";
            BTNode* ptr=st.front();
            if(ptr->left) st.push(ptr->left);
            if(ptr->right) st.push(ptr->right);
            st.pop();
        }
    }
}
int sumAtKthLevel(BTNode* root,string s,int k,int sum){
    if(root==NULL) return sum;
    if(s.length()==k){
        sum+=root->val;
        return sum;
    }
    sum=sumAtKthLevel(root->left,s+'0',k,sum);
    sum=sumAtKthLevel(root->right,s+'1',k,sum);
    return sum;
}
int main(){
    BTNode* root=NULL;
    while(1){
        root=NULL;
        pos=0;
        int p;
        cout<<"Enter 1 - To enter PreOrder & InOrder to find PostOrder: "<<endl;
        cout<<"Enter 2 - To enter PostOrder & InOrder to find PreOrder: "<<endl;
        cout<<"Enter 0 - To exit"<<endl;
        cin>>p;
        switch(p){
            case 1:{
                int n;
                cin>>n;
                vector<int> preO(n,0),inO(n,0);
                for(int i=0;i<n;i++) cin>>preO[i];
                for(int i=0;i<n;i++) cin>>inO[i];
                root=buildBST_Pre(0,n-1,preO,inO,root);
                cout<<"Post Order: ";
                postOrder(root);
                cout<<endl;
                break;
            }
            case 2:{
                int n;
                cin>>n;
                vector<int> postO(n,0),inO(n,0);
                for(int i=0;i<n;i++) cin>>postO[i];
                for(int i=0;i<n;i++) cin>>inO[i];
                reverse(postO.begin(),postO.end());
                root=buildBST_Post(0,n-1,postO,inO,root);
                cout<<"Pre Order: ";
                preOrder(root);
                cout<<endl;
                break;
            }
            case 0: return 0;
        }
        cout<<"Level Order: ";
        addAddrToStack(root);
        levelOrder(root);
        cout<<endl;
        cout<<"Right View: ";
        rightView(root);
        cout<<endl;
        cout<<"Left View: ";
        leftView(root);
        cout<<endl;
        int k;
        cin>>k;
        string s;
        cout<<sumAtKthLevel(root,s,k,0)<<endl;
    }
}