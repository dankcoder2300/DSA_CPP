// Program to find the nth root of a number
#include<bits/stdc++.h>
using namespace std;

//methdod 1: using linear search
// long long func(int base, int exp)
// {
//     long long ans=1;

//     while(exp>0){
//         if(exp%2){
//             exp--;
//             ans=ans*base;
//         }
//         else{
//             exp/=2;
//             base=base*base;
//         }
//     }
//     return ans;
// }

// int Nth_Root(int n, int m)
// {
//     for(int i=1;i<=m;i++){
//         long long val=func(i,n);

//         if(val==m*1ll){
//             return i;
//         }
//         else if(val>m*1ll){
//             break;
//         }
//     }
//     return -1;
// }

//Method 2: using binary search method
long long func(int base, int exp)
{
    long long ans=1;

    while(exp>0){
        if(exp%2){
            exp--;
            ans=ans*base;
        }
        else{
            exp/=2;
            base=base*base;
        }
    }
    return ans;
}

int Nth_Root(int n, int m)
{
    long long low=1,high=m;

    while(low<=high){
        int mid=(low+high)/2;

        long long val=func(mid,n);

        if(val==m*1ll)
        return mid;

        else if(val<m*1ll)
        low=mid+1;

        else
        high=mid-1;
    }
    return -1;
}

int main()
{
    int m;
    cout<<"Enter the Number: "<<endl;
    cin>>m;
    int n;
    cout<<"Enter the nth root number: "<<endl;
    cin>>n;

    int ans= Nth_Root(n,m);
    cout<<ans<<endl;

    return 0;
}
