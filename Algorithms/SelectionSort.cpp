#include<bits/stdc++.h>
using namespace std;

void Sort(int* arr, int n){
    for(int i=0;i<n;i++){
        int m=arr[i],index=i;
        for(int j=i;j<n;j++){
            if(m>arr[j]){
                m=arr[j];
                index=j;
            }
        }
        m=arr[i];
        arr[i]=arr[index];
        arr[index]=m;
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Sort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}