#include<bits/stdc++.h>
using namespace std;

vector<int> LASA(int arr[], int n){
    vector<int> index={0,1};
    for(int i=0;i<n-1;i++){
        int diff=arr[i]-arr[i+1];
        for(int j=i+1;j<n;j++){
            bool f=true;
            for(int k=i+1;k<=j;k++){
                if(arr[k-1]-arr[k]!=diff)
                {
                    f=false;
                    break;
                }
            }
            if(f && j-i>index[1]-index[0]){
                index[0]=i;
                index[1]=j;
            }
        }
    }
    return index;
}

vector<int> LASA2(int arr[], int n){
    vector<int> index={0,1},mindex={0,1};
    int diff=arr[0]-arr[1];
    for(int i=2;i<n;i++){
        if(arr[i-1]-arr[i]==diff && index[1]<i)
            index[1]=i;
        else{
            index[0]=i-1;
            index[1]=i;
            diff=arr[i-1]-arr[i];
        }
        if(index[1]-index[0]>mindex[1]-mindex[0]){
            mindex[1]=index[1];
            mindex[0]=index[0];
        }
    }
    return mindex;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> index=LASA2(arr,n);
    cout<<"Longest Arithmetic Sub-Array: ";
    for(int i=index[0];i<=index[1];i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}