#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &nums,int start,int mid,int end){
    int l1=mid-start+1,l2=end-mid;
    vector<int> arr1(l1),arr2(l2);
    for(int i=0;i<l1;i++) arr1[i]=nums[start+i];
    for(int i=0;i<l2;i++) arr2[i]=nums[mid+1+i];
    int i=0,j=0,k=start;
    while(i<l1 && j<l2){
        if(arr1[i]<arr2[j]){
            nums[k]=arr1[i];
            i++;
        }
        else{
            nums[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<l1){
        nums[k]=arr1[i];
        k++;
        i++;
    }

    while(j<l2){
        nums[k]=arr2[j];
        k++;
        j++;
    }
}
void MergeSort(vector<int> &nums,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        MergeSort(nums,start,mid);
        MergeSort(nums,mid+1,end);
        Merge(nums,start,mid,end);
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    MergeSort(nums,0,nums.size());
    for(auto i:nums) cout<<i<<"(*)";
    cout<<endl;
}