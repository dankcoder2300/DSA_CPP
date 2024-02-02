/*You are given an array of integers ‘arr’ and an integer i.e. a threshold value ‘limit’. Your task is to find the smallest 
positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division’s result
is less than or equal to the given threshold value.*/
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int smallestDivisor(vector<int> &arr,int limit){
//     for(int i=1;i<=*max_element(arr.begin(),arr.end());i++){
//         int sum=0;

//         for(int j=0;j<arr.size();j++){
//             sum+=ceil((double)(arr[j])/(double)(i));
//         }
//         if(sum<=limit){
//             return i;
//         }
//     }
//     return -1;
// }

//method 2: using binary search(optimal approach)
int sumDivisor(vector<int> &arr,int div){
    int sum=0;

    for(int i=0;i<arr.size();i++){
        sum+=ceil((double)(arr[i])/(double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int> arr,int limit){
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    int ans=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(sumDivisor(arr,mid)<=limit){
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
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}