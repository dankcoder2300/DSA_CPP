//Program to find the square root of a given number
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int squareRoot(int n)
// {
//     int ans=0;

//     for(long long i=0;i<=n;i++)
//     {
//         long long val=i*i;

//         if(val<=n*1ll)
//         ans=i;

//         else
//         break;
//     }
//     return ans;
// }

//method 2: using optimal approach
// int squareRoot(int n)
// {
//     return sqrt(n);
// }

//method 3: using optimal approach 2
int squareRoot(int n)
{
    int low=1;
    int high=n;
    int ans=0;

    while(low<=high)
    {
        long long mid=(low+high)/2;
        long long val=mid*mid;

        if(val<=n*1ll)
        {
            ans=mid;
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<"The square root of a given number is: "<<squareRoot(n)<<endl;

    return 0;
}