#include<bits/stdc++.h>
using namespace std;

void Sort(int* arr, int n){
    for(int i=1;i<n;i++){
        int current=arr[i],j=i-1;
        while(j>=0 && arr[j]>current){
            for(int j=0;j<n;j++) cout<<arr[j]<<"()";
            cout<<endl;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
        for(int j=0;j<n;j++) cout<<arr[j]<<"(*)";
        cout<<endl;
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