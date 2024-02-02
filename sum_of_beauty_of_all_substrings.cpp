// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.
#include<bits/stdc++.h>
using namespace std;

// method 1: using hashmaps
int beauty(int arr[])
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<26;i++)
        {
            maxi=max(maxi,arr[i]);
            if(arr[i]>=1)
            mini=min(mini,arr[i]);
        }
        return maxi-mini;
    }

    int beautySum(string str) {
        int n=str.size();
        int res=0;

        for(int i=0;i<n;i++)
        {
            int arr[26]={0};

            for(int j=i;j<n;j++)
            {
                arr[str[j]-'a']++;
                res+=beauty(arr);
            }
        }
        return res;
}

int main()
{
    string str;
    cout<<"Enter the string: "<<endl;
    cin>>str;

    cout<<beautySum(str)<<endl;

    return 0;
}