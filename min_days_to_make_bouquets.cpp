/*You are given ‘N’ roses and you are also given an array ‘arr’  where ‘arr[i]’  denotes that the ‘ith’ rose will bloom on the
‘arr[i]th’ day.You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require 
exactly ‘k’ adjacent bloomed roses to make a single bouquet.Find the minimum number of days required to make at least ‘m’ 
bouquets each containing ‘k’ roses. Return -1 if it is not possible.*/
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// bool possible(vector<int> &arr, int day, int m, int k){
//     int cnt=0;
//     int noOfBqts=0;

//     for(int i=0;i<arr.size();i++){
//         if(arr[i]<=day){
//             cnt++;
//         }
//         else{
//             noOfBqts+=cnt/k;
//             cnt=0;
//         }
//     }
//     noOfBqts+=cnt/k;

//     return (noOfBqts>=m);
// }

// int min_days(vector<int> &arr, int m, int k){
//     long long val= m*1ll*k*1ll;
//     if(val>arr.size()){
//         return -1;
//     }

//     for(int i=*min_element(arr.begin(),arr.end());i<=*max_element(arr.begin(),arr.end());i++){
//         if(possible(arr,i,m,k)){
//             return i;
//         }
//     }

//     return -1;
// }

//method 2: using binary search(optimal method)
bool possible(vector<int> &arr, int day, int m, int k){
    int cnt=0;
    int noOfBqts=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noOfBqts+=cnt/k;
            cnt=0;
        }
    }
    noOfBqts+=cnt/k;

    return (noOfBqts>=m);
}

int min_days(vector<int> &arr, int m, int k){
    long long val=m*1ll*k*1ll;
    if(val>arr.size()){
        return -1;
    }

    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(possible(arr,mid,m,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = min_days(arr, m, k);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}