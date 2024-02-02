//WAP to count no of digits in number

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cout<<"Enter the number: ";
    cin>>n;

    while(n!=0)
    {
        ans++;
        n=n/10;
    }
    cout<<"Number of didgits in number is: "<<ans<<endl;

    return 0;
}