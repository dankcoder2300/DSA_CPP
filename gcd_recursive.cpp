//WAP to calculate gcd or hcf by recursive

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    return a;

    else
    return gcd(b,a%b);
}
int main()
{
    int m,n;
    cout<<"Enter the first number: ";
    cin>>m;
    cout<<"Enter the second number: ";
    cin>>n;
    int ans=gcd(m,n);
    cout<<"GCD of two numbers is: "<<ans<<endl;

    return 0;
}