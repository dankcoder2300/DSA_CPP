// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty 
// substring of num, or an empty string "" if no odd integer exists.A substring is a contiguous sequence of characters within a string.
#include<bits/stdc++.h>
using namespace std;

 string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }

int main()
{
    string str;
    cout<<"Enter the string: "<<endl;
    getline(cin,str);
    cout<<"The largest odd number in a string is: "<<largestOddNumber(str)<<endl;

    return 0;
}
