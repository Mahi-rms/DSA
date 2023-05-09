#include<bits/stdc++.h>
using namespace std;

struct BSTNode{
    BSTNode* left;
    int data;
    BSTNode* right;
};

struct Node{
    BSTNode* addr;
    Node* next;
};
Node* head;

BSTNode* GetNode(int data){
    BSTNode* node=new BSTNode();
    node->left=NULL;
    node->data=data;
    node->right=NULL;
    return node;
}

BSTNode* min(BSTNode* ptr){
    while(ptr->left)
        ptr=ptr->left;
    return ptr;
}

BSTNode* max(BSTNode* ptr){
    while(ptr->right)
        ptr=ptr->right;
    return ptr;
}

BSTNode* insert(BSTNode* ptr, int a){
    if(ptr==NULL)
        ptr=GetNode(a);
    else if(a<=ptr->data)
        ptr->left=insert(ptr->left,a);
    else
        ptr->right=insert(ptr->right,a);
    return ptr;
}

BSTNode* find_parent(BSTNode* ptr,BSTNode* n){
    if(ptr->right==n)
        return ptr;
    else
        return find_parent(ptr->right,n);
}
BSTNode* Delete(BSTNode* ptr, int a){
    if(ptr!=NULL){
        if(ptr->data==a){
            BSTNode* n=max(ptr->left);
            ptr->data=n->data;
            BSTNode* p=find_parent(ptr->left,n);
            p->right=n->left;
            delete n;
        }
        else if(a<ptr->data)
            return Delete(ptr->left,a);
        else
            return Delete(ptr->right,a);
    }
    return ptr;
}
bool Search(BSTNode* ptr, int a){
    if(ptr!=NULL){
        if(ptr->data==a)
            return true;
        else if(a<ptr->data)
            return Search(ptr->left,a);
        else
            return Search(ptr->right,a);
    }
    else
        return false;
}

int height(BSTNode* ptr, int c, int m){
    if(ptr){
        c++;
        m=height(ptr->left,c,m);
        m=height(ptr->right,c,m);
    }
    if(c>m)
        return c;
    else
        return m;
}

void print(BSTNode* ptr){
    if(ptr!=NULL){
        cout<<ptr->data<<" | ";
        print(ptr->left);
        print(ptr->right);
    }
}
void add_new_addr_node(BSTNode* ptr){
    if(ptr){
        Node* temp=new Node();
        temp->addr=ptr;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            return;
        }
        Node* temp1=head;
        while(temp1->next)
            temp1=temp1->next;
        temp1->next=temp;
    }
}
void level_order_traversal(BSTNode* ptr){
    add_new_addr_node(ptr->left);
    add_new_addr_node(ptr->right);
    cout<<ptr->data<<" | ";
    Node* temp=head;
    head=head->next;
    delete temp;
    if(head)
        level_order_traversal(head->addr);
}

void in_order_traversal(BSTNode* ptr){
    if(ptr){
        in_order_traversal(ptr->left);
        cout<<ptr->data<<" | ";
        in_order_traversal(ptr->right);
    }
}

void pre_order_traversal(BSTNode* ptr){
    if(ptr){
        cout<<ptr->data<<" | ";
        pre_order_traversal(ptr->left);
        pre_order_traversal(ptr->right);
    }
}

void post_order_traversal(BSTNode* ptr){
    if(ptr){
        post_order_traversal(ptr->left);
        post_order_traversal(ptr->right);
        cout<<ptr->data<<" | ";
    }
}

int main(){
    BSTNode* root=NULL;
    head=NULL;
    int n,a;
    while(1){
        cout<<"Enter...\n";
        cout<<"1-to insert a number\n";
        cout<<"2-to remove a number\n";
        cout<<"3-to search a number\n";
        cout<<"4-to get smallest number\n";
        cout<<"5-to get largest number\n";
        cout<<"6-to get height of the tree\n";
        cout<<"7-for Level-Order traversal of the binary tree\n";
        cout<<"8-for In-Order traversal of the binary tree\n";
        cout<<"9-for Pre-Order traversal of the binary tree\n";
        cout<<"10-for Post-Order traversal of the binary tree\n";
        cout<<"11-to delete a number from the binary tree\n";
        cout<<"0-to exit\n";
        cin>>n;
        if(n==0)
            break;
        switch(n){
            case 1:{
                cout<<"Enter the number you want to insert :\n";
                cin>>a;
                root=insert(root,a);
            }
            break;
            case 2:{
                cout<<"Enter the number's place from which you want to remove..space separatedely:\n";
                cin>>a;
                //c=remove(a);
            }
            break;
            case 3:{
                cout<<"Enter the number you want to search :\n";
                cin>>a;
                if(Search(root,a))
                    cout<<"Number found in the tree\n";
                else
                    cout<<"Number not found\n";
            }
            break;
            case 4:{
                cout<<"Smallest Number in the tree: "<<min(root)->data<<"\n";
            }
            break;
            case 5:{
                cout<<"Largest Number in the tree: "<<max(root)->data<<"\n";
            }
            break;
            case 6:{
                cout<<"Height of the tree: "<<height(root,-1,-1)<<"\n";
            }
            break;
            case 7:{
                add_new_addr_node(root);
                cout<<"Level-Order Traversal of the binary tree: ";
                level_order_traversal(root);
                cout<<"\n";
            }
            break;
            case 8:{
                cout<<"In-Order Traversal of the binary tree: ";
                in_order_traversal(root);
                cout<<"\n";
            }
            break;
            case 9:{
                cout<<"Pre-Order Traversal of the binary tree: ";
                pre_order_traversal(root);
                cout<<"\n";
            }
            break;
            case 10:{
                cout<<"Post-Order Traversal of the binary tree: ";
                post_order_traversal(root);
                cout<<"\n";
            }
            break;
            case 11:{
                cout<<"Enter a number to delete it from the binary tree: ";
                cin>>n;
                root=Delete(root,n);
                cout<<"\n";
            }
            break;
            default:
                cout<<"Invalid Selection. Please select from the given list.\n";
            break;
        }
        print(root);
        cout<<"\n";
    }
}