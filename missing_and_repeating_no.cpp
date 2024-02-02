//Program to find missing and repeating no in an array of size n-1 consisting of numbers between 1-n
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force approach
// vector<int> missingAndRepeating(int arr[], int n)
// {
//     int missing=-1;
//     int repeating=-1;

//     for(int i=1;i<=n;i++)
//     {
//         int cnt=0;

//         for(int j=0;j<n;j++)
//         {
//             if(arr[j]==i)
//             {
//                 cnt++;
//             }
//         }
//         if(cnt==0)
//         missing=i;
//         else if(cnt==2)
//         repeating=i;

//         if(repeating!=-1 && missing!=-1)
//         break;
//     }
//     return {missing,repeating};
// }

//method 2: using hashing (better approach)
// vector<int> missingAndRepeating(int arr[],int n)
// {
//     int missing=-1,repeating=-1;
//     int hash[n+1]={0};

//     for(int i=0;i<n;i++)
//     {
//         hash[arr[i]]++;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(hash[i]==0)
//         missing=i;
//         else if(hash[i]==2)
//         repeating=i;

//         if(repeating!=-1 && missing!=-1)
//         break;
//     }
//     return {missing,repeating};
// }

//method 3: using summation and square summation method (optimal method)
vector<int> missingAndRepeating(int arr[], int n)
{
    int x;      //repeating no
    int y;      //missing no

    int sum_n=(n*(n+1))/2;
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    //x-y
    int val1=sum-sum_n;

    int sum2_n=(n*(n+1)*(2*n+1))/6;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
        sum2+=(arr[i]*arr[i]);
    }
    //x^2-y^2
    int val2=sum2-sum2_n;
    //x+y
    int val=val2/val1;

    //repeating no
    x=(val+val1)/2;
    //missing no
    y=(val-val1)/2;

    return {y,x};
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array between 1-"<<n<<": ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans=missingAndRepeating(arr,n);
    cout<<"Missing no. in array is: "<<ans[0]<<" and Repeating no. in array is: "<<ans[1]<<endl;

    return 0;
}