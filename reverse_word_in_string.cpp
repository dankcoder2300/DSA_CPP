//Given a string s, reverse the words of the string.
#include<bits/stdc++.h>
using namespace std;

// method1 : using stack approach
// string reverseString(string str){
//     stack<string> st;
//     string s="";
//     for(int i=0;i<str.size();i++){
//         if(str[i]==' '){
//             st.push(s);
//             s="";
//         }
//         else{
//             s+=str[i];
//         }
//     }
//     string ans="";
//     while(st.size()!=1){
//         ans=ans+st.top()+" ";
//         st.pop();
//     }
//     ans+=st.top();

//     return ans;
// }

// method 2: using two pointers approach
string reverseString(string str){
    string temp="";
    string ans="";

    int low=0;
    int high=str.size()-1;

    while(low<=high){
        if(str[low]==' ')
        {
            if(ans!="")
            {
                if(temp!="")
                ans=temp+" "+ans;
            }
            else{
                ans=temp;
            }
            temp="";
        }
        else if(str[low]!=' '){
            temp+=str[low];
        }

        low++;
    }
        if(temp!=""){
            if(ans!=""){
                ans=temp+" "+ans;
            }
            else{
                ans=temp;
            }
        }
    return ans;
}

int main()
{
    string str;
    cout<<"Enter the string: "<<endl;
    getline(cin,str);

    cout<<"The string after reversing word is: "<<reverseString(str);

    return 0;    
}