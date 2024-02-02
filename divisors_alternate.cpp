// WAP to print all divisors of a given numbers

#include<bits/stdc++.h>
using namespace std;

void printalldivisors(int n)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
        cout<<i<<" ";

        if(i!=n/i)
        cout<<n/i<<" ";
    }
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    printalldivisors(n);
    return 0;
}