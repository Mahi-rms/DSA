#include<bits/stdc++.h>
using namespace std;
void pre_dfs(int n, vector<int>& visited, map<int,vector<int>>& adj){
    if(visited[n]){
        cout<<n<<"(*)";
        visited[n]=0;
    }
    for(int i:adj[n]){
        pre_dfs(i,visited,adj);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> adj;
    vector<int> visited(n+1,1);
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }
    pre_dfs(1,visited,adj);
}