/*You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. Find the ‘kth’ positive integer missing from ‘vec’.*/
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int missingK(vector<int> &arr,int n,int k){
//     for(int i=0;i<n;i++){
//         if(arr[i]<=k){
//             k++;
//         }
//         else{
//             break;
//         }
//     }
//     return k;
// }

//method 2: using binary search(optimal approach)
int missingK(vector<int> &arr, int k){
    int low=0,high=arr.size()-1;

    while(low<=high){
        int mid=(low+high)/2;

        int missing=arr[mid]-(mid+1);
        
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    return k+high+1;
}

int main()
{
    vector<int> vec = {2,3,4,7,11};
    int n = 5, k = 5;
    int ans = missingK(vec, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}