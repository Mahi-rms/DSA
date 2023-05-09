#include<bits/stdc++.h>
using namespace std;
void recursion(string s,string res){
    if(s.size()==0){
        cout<<res<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        recursion(s.substr(0,i)+s.substr(i+1),res+s[i]);
    }
}
int main(){
    string s;
    cin>>s;
    recursion(s,"");
}