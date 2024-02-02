//WAP to check whether a number is armstrong number or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,cnt=0,rem,m,ans=0;
    cout<<"Enter the number: ";
    cin>>n;
    m=n,p=n;
    while(n!=0)
    {
        cnt++;
        n=n/10;
    }

    while(p!=0)
    {
        rem=p%10;
        ans=ans+pow(rem,cnt);
        p=p/10;
    }

    if(ans==m)
    cout<<"Number is Armstrong number "<<endl;
    else
    cout<<"Not a Armstrong number "<<endl;
    return 0;
}