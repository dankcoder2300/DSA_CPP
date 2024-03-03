//Program to find missing number in an array of size n-1 containing numbers between 1-n
#include<bits/stdc++.h> 
using namespace std;

// method 1: brute force linear search
// int missing_no(int arr[],int n)
// {
    // for(int i=1;i<=n;i++)
    // {
    //     int flag=0;

    //     for(int j=0;j<n-1;j++)
    //     {
    //         if(arr[j]==i)
    //         {
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==0)
    //     return i;
//     }
// }

// method 2:hashing
// int missing_no(int arr[],int n)
// {
    // int hash[n+1]={0};

    // for(int i=0;i<n-1;i++)
    // {
    //     hash[arr[i]]++;
    // }

    // for(int i=1;i<n;i++)
    // {
    //     if(hash[i]==0)
    //     return i;
    // }
    // return -1;
// }

// method 3: using sum difference approach
// int missing_no(int arr[],int n)
// {
    // int sum_n=(n*(n+1))/2;
    // int sum_array=0;
    // for(int i=0;i<n-1;i++)
    // {
    //     sum_array=sum_array+arr[i];
    // }

    // return sum_n-sum_array;
// }

//method 4: XOR operation approach
int missing_no(int arr[],int n)
{
    int xor1=0,xor2=0;
    for(int i=0;i<n-1;i++)
    {
        xor2=xor2^arr[i];       //xor array elements
        xor1=xor1^(i+1);        //xor n-1 numbers
    }
    xor1=xor1^n;                //xor remaining one element

    return (xor1^xor2);
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int m=n-1;
    int arr[m];
    cout<<"Enter the elements of array between 1-"<<n<<": ";
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    int ans=missing_no(arr,n);
    cout<<"Missing no. in array is: "<<ans<<endl;
}