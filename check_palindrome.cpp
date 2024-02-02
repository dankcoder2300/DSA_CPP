//WAP to check whether a number is palindrome or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,rem,m;
    cout<<"Enter the number: ";
    cin>>n;
    m=n;
    while(n!=0)
    {
        rem=n%10;
        ans=ans*10+rem;
        n=n/10;
    }

    if(ans==m)
    cout<<"Number is Palindronme "<<endl;
    else
    cout<<"Not a palindrome number "<<endl;
    return 0;
}