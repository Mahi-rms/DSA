#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
    vector<int> arr;
    int parent(int i){
        return (i-1)/2;
    }
    int leftchild(int i){
        return (2*i)+1;
    }
    int rightchild(int i){
        return (2*i)+2;
    }
    void heapify(int i){
        int l=leftchild(i),r=rightchild(i),lind=i;
        if(l<arr.size() && arr[lind]<arr[l]) lind=l;
        if(r<arr.size() && arr[lind]<arr[r]) lind=r;
        if(lind!=i){
            heapify(l);
            heapify(r);
            swap(arr[i],arr[lind]);
        }
    }
    public:
    void push(int p){
        arr.push_back(p);
        int i=arr.size()-1;
        while(i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
        printHeap();
    }
    void remove(int p){
        arr.erase(arr.begin()+p);
        heapify(p);
        printHeap();
    }
    void printHeap(){
        cout<<"(*)";
        for(int i: arr) cout<<i<<" ";
        cout<<endl;
    }
};
int main(){
    int n;
    MaxHeap mh;
    while(1){
        cout<<"Enter 0 to exit: "<<endl;
        cout<<"Enter 1 to insert: "<<endl;
        cout<<"Enter 2 to delete: "<<endl;
        cout<<"Enter 3 to pop max element: "<<endl;
        cin>>n;
        switch(n){
            case 1:{
                int p;
                cout<<"Enter a value to insert: ";
                cin>>p;
                mh.push(p);
                break;
            }
            case 2:{
                int p;
                cout<<"Enter the index to delete: ";
                cin>>p;
                mh.remove(p);
                break;
            }
            case 3:{
                mh.remove(0);
                break;
            }
            default:
                return 0;
        }
    }
}