#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000

void shift_left(int* arr,int b,int c){
    for(int i=b;i<c-1;i++)
        arr[i]=arr[i+1];
}
void shift_right(int* arr,int b,int c){
    for(int i=c;i>b;i--)
        arr[i]=arr[i-1];
}
int insert(int* arr,int a,int b,int c){
    if(b<c){
        shift_right(arr,b,c);
    }
    else if(b>c){
        cout<<"Entered index doesn't exist.\n";
        return c;
    }
    arr[b]=a;
    c++;
    return c;
}
int remove(int* arr,int b,int c){
    if(b<c-1){
        shift_left(arr,b,c);
    }
    else if(b>=c){
        cout<<"Entered index doesn't exist.\n";
        return c;
    }
    c--;
    return c;
}
int main(){
    int arr[MAX_SIZE];
    int n,a,b,c=0;
    while(1){
        cout<<"Enter...\n";
        cout<<"1-to insert a number\n";
        cout<<"2-to remove a number\n";
        cout<<"0-to exit\n";
        cin>>n;
        if(n==0)
            break;
        switch(n){
            case 1:
            cout<<"Enter the number and at which place do you want to insert..space separatedely:\n";
            cin>>a>>b;
            c=insert(arr,a,b,c);
            break;
            case 2:
            cout<<"Enter the number's place from which you want to remove..space separatedely:\n";
            cin>>b;
            c=remove(arr,b,c);
            break;
            default:
            cout<<"Invalid Selection. Please select from the given list.";
            break;
        }
        for(int i=0;i<c;i++)
            cout<<arr[i]<<",";
        cout<<endl;
    }
}