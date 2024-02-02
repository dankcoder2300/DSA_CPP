//Program  to find unique quads that add up to give a sum of zero.
#include<bits/stdc++.h>
using namespace std;

//method 1: using 4 loops (brute force approach)
// vector<vector<int>> fourSum(int arr[],int n,int target)
// {
//     set<vector<int>> st;

//     for(int i=0;i<n-3;i++)
//     {
//         for(int j=i+1;j<n-2;j++)
//         {
//             for(int k=j+1;j<n-1;j++)
//             {
//                 for(int l=k+1;l<n;l++)
//                 {
//                     if(arr[i]+arr[j]+arr[k]+arr[l]==target)
//                     {
//                         vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;    
// }

//method 2: using three for loops and set data structure (better approach)
// vector<vector<int>> fourSum(int arr[],int n,int target)
// {
//     set<vector<int>> st;

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             set<int> hashset;
//             for(int k=j+1;k<n;k++)
//             {
//                 int fourth=target-(arr[i]+arr[j]+arr[k]);
//                 if(hashset.find(fourth)!=hashset.end())
//                 {
//                     vector<int> temp={arr[i],arr[j],arr[k],fourth};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

//method 4: using four pointers approach (optimal approach)
vector<vector<int>> fourSum(int arr[],int n, int target)
{
    vector<vector<int>> ans;
    sort(arr,arr+n);

    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        continue;

        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            continue;

            int k=j+1,l=n-1;
            while(k<l)
            {
                int sum=arr[i]+arr[j]+arr[k]+arr[l];
                if(sum<target)
                k++;
                else if(sum>target)
                l--;
                else{
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++,l--;
                    while(k<l && arr[k]==arr[k-1])
                    k++;
                    while(k<l && arr[l]==arr[l+1])
                    l--;
                }
            }
        }
    }
    return ans;
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
    int k;
    cout<<"Enter the target: ";
    cin>>k;

    vector<vector<int>> ans=fourSum(arr,n,k);
    if(ans.size()==0)
    {
        cout<<"No such Quads present in an array!!!";
        exit(0);
    }

    cout<<"Quads that adds to sum 0 are: ";
    for(auto it:ans)
    {
        cout<<"[ ";
        for(auto itt:it)
        {
            cout<<itt<<" ";
        }
        cout<<"]";
    }
    

    return 0;
}