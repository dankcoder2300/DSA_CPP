// Given a string s, return the longest palindromic substring in s.
#include<bits/stdc++.h>
using namespace std;

//method 1 : using expand center method(two pointer method)
string longestPalindrome(string str) {
        int n=str.size();

        if(n<=1)
        return str;

        string lps="";

        for(int i=1;i<n;i++)
        {
            //considering odd length case
            int low=i;
            int high=i;

            while(str[low]==str[high]){
            low--,high++;
            
            if(low==-1 || high==n)
            break;
            }
            string palindrome=str.substr(low+1,high-low-1);
            if(palindrome.size()>lps.size())
            lps=palindrome;

            //considering even length case
            low=i-1;
            high=i;

            while(str[low]==str[high])
            {
                low--,high++;

                if(low==-1 || high==n)
                break;
            }

            palindrome=str.substr(low+1,high-low-1);
            if(palindrome.size()>lps.size())
            lps=palindrome;
        }

        return lps;
}

int main()
{
    string str;
    cout<<"Enter the string: "<<endl;
    cin>>str;

    cout<<longestPalindrome(str)<<endl;

    return 0;
}