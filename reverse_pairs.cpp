//Program to finf reverse pairs where i<j and arr[i]>2*arr[j].
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int reversePairs(int arr[],int n)
// {
//     vector<pair<int,int>> temp;
//     int cnt=0;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]>2*arr[j])
//             {
//             cnt++;
//             }
//         }
//     }
//     return cnt;    
// }

// using merge sort approach
void merge(int arr[],int low,int mid,int high)
{
vector<int> temp;
int left=low;
int right=mid+1;

while(left<=mid && right<=high)
{
    if(arr[left]<arr[right])
    {
        temp.push_back(arr[left]);
        left++;
    }
    else
    {
        temp.push_back(arr[right]);
        right++;
    }
}

while(left<=mid)
{
    temp.push_back(arr[left]);
    left++;
}
while(right<=high)
{
    temp.push_back(arr[right]);
    right++;
}

for(int i=low;i<=high;i++)
{
    arr[i]=temp[i-low];
}

}

int countPairs(int arr[],int low,int mid, int high)
{
    int cnt=0;
    int right=mid+1;

    for(int i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>2*arr[right])
        {
            right++;
        }
        cnt+=right-(mid+1);
    }
    return cnt;
}

int merge_sort(int arr[],int low,int high)
{
    int cnt=0;
    if(low>=high)
    return cnt;

    int mid=(low+high)/2;

    cnt+=merge_sort(arr,low,mid);
    cnt+=merge_sort(arr,mid+1,high);
    cnt+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);

    return cnt;
}

int reversePairs(int arr[],int n)
{
    return merge_sort(arr,0,n-1);
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"The number of reverse pairs in an array are: "<<reversePairs(arr,n)<<endl;

    return 0;
}

