// WAP to check whether number is prime or not

#include<bits/stdc++.h>
using namespace std;

void checkprime(int n)
{
    int cnt=0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout<<"Number is not prime"<<endl;
            cnt++;
            break;
        }
    }
    if(cnt==0)
    cout<<"Number is prime"<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    checkprime(n);

    return 0;
}