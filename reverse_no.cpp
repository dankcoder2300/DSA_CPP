//WAP to reverse a number

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,rem;
    cout<<"Enter the number: ";
    cin>>n;

    while(n!=0)
    {
        rem=n%10;
        ans=ans*10+rem;
        n=n/10;
    }
    cout<<"Reversed number is: "<<ans<<endl;

    return 0;
}