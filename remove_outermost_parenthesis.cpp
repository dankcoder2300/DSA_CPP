//Program to remove outermost parenthesis of a valid string
#include<bits/stdc++.h>
using namespace std;

//method 1: using stack based approach
string func(string str){
    stack<char> st;
    string ans="";

    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            if(st.size()>0){
                ans=ans+str[i];
            }
            st.push(str[i]);
        }
        else{
            st.pop();
            if(st.size()>0){
                ans=ans+str[i];
            }
        }
    }

    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<"The string after removing outermost parenthesis is: "<<func(str)<<endl;

    return 0;
}