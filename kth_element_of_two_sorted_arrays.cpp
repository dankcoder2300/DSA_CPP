// Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position 
// of the final sorted array.
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
//     int p1=0,p2=0,counter=0,answer=0;

//     while(p1<n && p2<m) {
//         if(counter == k) break;
//         else if(arr1[p1]<arr2[p2]) {
//             answer = arr1[p1];
//             ++p1;
//         }
//         else {
//             answer = arr2[p2];
//             ++p2;
//         }
//         ++counter;
//     }
//     if(counter != k) {
//         if(p1 != n-1) 
//             answer = arr1[k-counter+1];
//         else 
//             answer = arr2[k-counter+1];
//     }
//     return answer;
// }

//method 2: using binary search(optimal method)
int kthElement(vector<int> &arr1,vector<int> &arr2, int m, int n,int k){
    if(m>n){
        return kthElement(arr2,arr1,n,m,k);
    }

    int low=max(0,k-n);
    int high=min(k,m);

    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=k-cut1;

        int left1= cut1==0 ? INT_MIN : arr1[cut1-1];
        int left2= cut2==0 ? INT_MIN : arr2[cut2-1];
        
        int right1= cut1==0 ? INT_MAX : arr1[cut1];
        int right2= cut2==0 ? INT_MAX : arr2[cut2];

        if(left1<=right2 && left2<=right1){
            return max(left1,left2);
        }
        else if(left1>right2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }

    return 1;
}

int main() {
    vector<int> array1 = {1,2,6,8,9};
    vector<int> array2 = {3,4};
    int m = array1.size();
    int n = array2.size();
    int k = 6;
    cout<<"The element at the "<< k<<"th position in the final sorted array is "
    <<kthElement(array1,array2,m,n,k);
    return 0;
}
