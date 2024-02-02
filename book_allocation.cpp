/*Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of 
students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
If the allocation of books is not possible. return -1
*/

#include<bits/stdc++.h>
using namespace std;

//method 1: using linear search(brute force method)
// int countStudents(vector<int> & arr, int maxPages){
//     int studentCnt=1;
//     int pages=0;

//     for(int i=0;i<arr.size();i++){
//         if(pages+arr[i]<=maxPages){
//             pages+=arr[i];
//         }
//         else{
//             studentCnt++;
//             pages=arr[i];
//         }
//     }

//     return studentCnt;
// }

// int findPages(vector<int> &arr,int n,int m){
    
//     int low=*max_element(arr.begin(),arr.end());
//     int high=accumulate(arr.begin(),arr.end(),0);

//     for(int i=low;i<=high;i++){
//         if(countStudents(arr,i)==m){
//             return i;
//         }
//     }

//     return -1;
// }

//method 2: using binary search(optimal method)
int countStudents(vector<int> & arr, int maxPages){
    int studentCnt=1;
    int pages=0;

    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]<=maxPages){
            pages+=arr[i];
        }
        else{
            studentCnt++;
            pages=arr[i];
        }
    }

    return studentCnt;
}

int findPages(vector<int> &arr, int n, int m){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int ans=-1;

    if(m>n){
        return -1;
    }
    
    while(low<=high){
        int mid=(low+high)/2;

        if(countStudents(arr,mid)>m){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}