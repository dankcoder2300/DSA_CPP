//WAP to calculate gcd or hcf

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cout<<"Enter the first number: ";
    cin>>m;
    cout<<"Enter the second number: ";
    cin>>n;

    for(int i=min(m,n);i>=2;i--)
    {
        if(m%i==0&& n%i==0)
        {
            cout<<"GCD is: "<<i<<endl;
            break;
        }
    }
    return 0;
}