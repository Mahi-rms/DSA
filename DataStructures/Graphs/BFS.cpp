#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> adj;
    queue<int> q;
    vector<int> visited(n,1);
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }
    map<int,vector<int>>::iterator it=adj.begin();
    q.push(it->first);
    visited[q.front()]=0;
    while(! q.empty()){
        for(int i:adj[q.front()]){
            if(visited[i]){
                q.push(i);
                visited[i]=0;
            }
        }
        cout<<q.front()<<"(*)";
        q.pop();
    }
}