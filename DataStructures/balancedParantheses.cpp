#include<bits/stdc++.h>
using namespace std;

bool is_valid(string str){
    int l=str.length(), top=-1;
    int arr[l];
    for(int i=0;i<l;i++){
        switch(str[i]){
            case ')':{
                if(arr[top]=='(')
                    top--;
                else
                    return false;
            }
            break;
            case '}':{
                if(arr[top]=='{')
                    top--;
                else
                    return false;
            }
            break;
            case ']':{
                if(arr[top]=='[')
                    top--;
                else
                    return false;
            }
            break;
            default:{
                top++;
                arr[top]=str[i];
            }
            break;
        }
    }
    if(top==-1)
        return true;
    else
        return false;
}
int main(){
    string str;
    cout<<"Enter the Parantheses: ";
    cin>>str;
    if(is_valid(str))
        cout<<"Valid Parantheses\n";
    else
        cout<<"Invalid Parantheses\n";
}