// Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median 
// is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average 
// of the two middle elements.
#include<bits/stdc++.h>
using namespace std;

//method 1: using merge-sort algorithm(brute force approach)
// double median(vector<int> &a, vector<int> &b){
//     int n1=a.size();
//     int n2=b.size();

//     int i=0,j=0;
//     vector<int> c;

//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             c.push_back(a[i]);
//             i++;
//         }
//         else{
//             c.push_back(b[j]);
//             j++;
//         }
//     }
//     while(i<n1){
//         c.push_back(a[i]);
//         i++;
//     }

//     while(j<n2){
//         c.push_back(b[j]);
//         j++;
//     }

//     int n=c.size();

//     if(n%2==1){
//         return (double)c[n/2];
//     }
    
//     return ((double)c[n/2]+(double)c[(n/2)-1])/2.0;
// }

//method 2:using binary search(optimal approach)
double median(vector<int> &arr1, vector<int> &arr2){
    int n1=arr1.size();
    int n2=arr2.size();

    if(n1>n2){
        return median(arr2,arr1);
    }
    
    int low=0;
    int high=n1;

    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=(n1+n2+1)/2-cut1;

        int left1= cut1==0 ? INT_MIN : arr1[cut1-1];
        int left2= cut2==0 ? INT_MIN : arr2[cut2-1];

        int right1= cut2==0 ? INT_MAX : arr1[cut1];
        int right2= cut2==0 ? INT_MAX : arr2[cut2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2)%2==0){
            return (max(left1,left2)+min(right1,right2))/2.0;
        }
        else{
            return max(left1,left2);
        }
    }
    else if(left1>right2){
        high=cut1-1;
    }
    else{
        low=cut1+1;
    }
    }

    return 0.0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}