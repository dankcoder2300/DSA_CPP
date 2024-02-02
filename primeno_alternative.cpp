// WAP to check whether number is prime or not

#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    bool ans=isprime(n);
    if(n!=1&& ans==true)
    cout<<"Number is prime"<<endl;
    else
    cout<<"Number is not prime"<<endl;

    return 0;
}