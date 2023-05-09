#include<bits/stdc++.h>
using namespace std;
int Quick(vector<int> &nums,int start,int end){
    int pivot=nums[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[end]);
    return i+1;
}
void QuickSort(vector<int> &nums,int start,int end){
    if(start<end){
        int pivot=Quick(nums,start,end);
        QuickSort(nums,start,pivot-1);
        QuickSort(nums,pivot+1,end);
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    QuickSort(nums,0,nums.size()-1);
    for(auto i:nums) cout<<i<<"(*)";
    cout<<endl;
}