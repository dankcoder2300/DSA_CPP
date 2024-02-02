//Program  to find unique triplets that add up to give a sum of zero.
#include<bits/stdc++.h>
using namespace std;

//method 1:using brute force approach
// vector<vector<int>> threeSum(int arr[],int n)
// {
//     set<vector<int>> st;
//     vector<int> temp;
//     for(int i=0;i<n-2;i++)
//     {
//         for(int j=i+1;j<n-1;j++)
//         {
//             for(int k=j+1;k<n;k++)
//             {
//                 temp.clear();
//                 if(arr[i]+arr[j]+arr[k]==0)
//                 {
//                 temp.push_back(arr[i]);
//                 temp.push_back(arr[j]);
//                 temp.push_back(arr[k]);
//                 }
//                 sort(temp.begin(),temp.end());
//                 if(temp.size()!=0)
//                 st.insert(temp);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

//method 2: using hashing (better approach)
// vector<vector<int>> threeSum(int arr[],int n)
// {
//     set<vector<int>> st;

//     for(int i=0;i<n;i++)
//     {
//         set<int> hashSet;
//         for(int j=i+1;j<n;j++)
//         {
//             int third= -(arr[i]+arr[j]);
//             if(hashSet.find(third)!=hashSet.end())
//             {
//                 vector<int> temp={arr[i],arr[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//         hashSet.insert(arr[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
    
//     return ans;
// }

//method 3:using three pointer approach (optimal approach)
vector<vector<int>> threeSum(int arr[],int n)
{
    vector<vector<int>> ans;
    sort(arr,arr+n);

    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        continue;

        int j=i+1, k=n-1;
        while(j<k)
        {
        int sum=arr[i]+arr[j]+arr[k];
            if(sum<0)
            j++;
            else if(sum>0)
            k--;
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])
                j++;
                while(j<k && arr[k]==arr[k+1])
                k--;
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

    vector<vector<int>> ans=threeSum(arr,n);
    if(ans.size()==0)
    {
        cout<<"No such triplets present in an array!!!";
        exit(0);
    }

    cout<<"Triplets that adds to sum 0 are: ";
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