// You are given a string 'str' of lowercase alphabets and an integer 'k' .
// Your task is to return the count all the possible substrings that have exactly 'k' distinct characters.
#include<bits/stdc++.h>
using namespace std;

// method 1: using hash map
int countSubStrings(string str, int k) 
{
    int n=str.size();
    int ans=0;

    for(int i=0;i<n;i++)
    {
        int arr[26]={0};
        int cnt=0;

        for(int j=i;j<n;j++)
        {
            //if char is not present in hash map
            if(arr[str[j]-'a']==0){
                cnt++;
                arr[str[j]-'a']++;
            }

            //if cnt becomes equal to k
            if(cnt==k)
            {
                ans++;
            }

            //if cnt becomes more than k
            if(cnt>k){
                break;
            }
        }
    }
    return ans;
}

int main()
{
    string str;
    cout<<"Enter the string: "<<endl;
    cin>>str;
    int k;
    cout<<"Enter the k: "<<endl;
    cin>>k;

    cout<<countSubStrings(str,k)<<endl;
}