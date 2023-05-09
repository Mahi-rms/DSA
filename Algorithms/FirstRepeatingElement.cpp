#include<bits/stdc++.h>
#define INT_M 1000002

using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    vector<int> carr(INT_M,-1);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int m=n;
    for(int i=0;i<n;i++){
        if(carr[arr[i]]+1){
            if(arr[i]<m) m=arr[i];
        }
        else carr[arr[i]]=i;
    }
    cout<<arr[m];
}