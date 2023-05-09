#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node * head;
void print(){
    Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<",";
        ptr=ptr->next;
    }
    cout<<"\n";
}
void printReverse(Node* ptr){
    if(ptr->next)
        printReverse(ptr->next);
    cout<<ptr->data<<",";
}
int insert(int a,int b,int c){
    if(b>c){
        cout<<"Entered Index doesn't exist.\n";
        return c;
    }
    Node* temp= new Node();
    temp->data=a;
    temp->next=NULL;
    if(b==0){
        Node* ptr=head;
        head=temp;
        temp->next=ptr;
    }
    else if(b==c){
        Node* ptr=head;
        while(ptr->next){
            ptr=ptr->next;
        }
        cout<<"\n";
        ptr->next=temp;
    }
    else{
        Node* ptr=head;
        b--;
        while(b--)
            ptr=ptr->next;
        temp->next=ptr->next;
        ptr->next=temp;
    }
    cout<<"Added "<<a<<" in to the Linked List\n";
    c++;
    return c;
}
int remove(int b,int c){
    if(b>=c){
        cout<<"Entered index doesn't exist.\n";
        return c;
    }

    if(b==0){
        head=head->next;
    }
    else if(b==c-1){
        Node* ptr=head;
        while(ptr->next->next)
            ptr=ptr->next;
        delete ptr->next;
        ptr->next=NULL;
    }
    else{
        Node* ptr=head;
        b--;
        while(b--)
            ptr=ptr->next;
        Node* temp=ptr->next;
        ptr->next=temp->next;
        delete temp;
    }
    c--;
    return c;
}
void reverse(){
    Node* pin=head;
    while(pin->next){
        pin=pin->next;
    }
    while(pin!=head){
        Node* temp=head;
        Node* ptr=head;
        while(ptr->next){
            ptr=ptr->next;
        }
        if(head->next==pin){   
            head=pin;
        }
        else{
            Node* temp1=head;
            while(temp1->next->next!=pin){
                temp1=temp1->next;
            }
            temp=temp1->next;
            temp1->next=pin;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
}

void reverse2(){
    Node* pin=head;
    while(pin->next){
        pin=pin->next;
    }
    Node* rev=pin;
    while(head!=pin){
        Node* ptr=head;
        while(ptr->next!=pin)
            ptr=ptr->next;
        pin->next=ptr;
        ptr->next=NULL;
        pin=ptr;
    }
    head=rev;
}
int main(){
    head=NULL;
    int n,a,b,c=0;
    while(1){
        cout<<"Enter...\n";
        cout<<"1-to insert a number\n";
        cout<<"2-to remove a number\n";
        cout<<"3-to reverse the list\n";
        cout<<"4-to print the list in reverse\n";
        cout<<"0-to exit\n";
        cin>>n;
        if(n==0)
            break;
        switch(n){
            case 1:{
                cout<<"Enter the number and at which place do you want to insert..space separatedely:\n";
                cin>>a>>b;
                c=insert(a,b,c);
            }
            break;
            case 2:{
                cout<<"Enter the number's place from which you want to remove..space separatedely:\n";
                cin>>b;
                c=remove(b,c);
            }
            break;
            case 3:
                reverse();  //method1
                reverse2(); //method2
            break;
            case 4:{
                Node* ptr=head;
                printReverse(ptr);
                cout<<"\n";
            }
            break;
            default:
                cout<<"Invalid Selection. Please select from the given list.\n";
            break;
        }
        print();
    }
}
