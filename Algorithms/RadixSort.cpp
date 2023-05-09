#include<bits/stdc++.h>
using namespace std;
void Sort(vector<int>& arr,int n){
    int ma=INT_MIN,q=10,c=1;
    for(int i:arr) ma=max(ma,i);
    while(ma%q!=ma){
        q*=10;
        c++;
    }
    int y=1,z;
    while(c--){
        z=y;
        y*=10;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        sort(arr.begin(),arr.end(),[&](int& a,int& b){
            return (a%y-a%z)<(b%y-b%z);
        });
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Sort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}