// Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.
// Assume – r*c is odd
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int Findmedian(vector<vector<int>> arr,int row, int col){
//     vector<int> median(row*col);
//     int index=0;

//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             median[index]= arr[i][j];
//             index++;
//         }
//     }
//     sort(median.begin(),median.end());

//     return median[(row*col)/2];
// }

//method 2: using binary search(optimal approach)
int upperbound(vector<int> arr,int x){
    int low=0;
    int high=arr.size()-1;
    int ans;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;    
}

int countSmallerEqual(vector<vector<int>> arr,int x){
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        cnt+=upperbound(arr[i],x);
    }
    return cnt;
}

int Findmedian(vector<vector<int>> arr,int row,int col){
    int req=(row*col)/2;

    int low=INT_MAX,high=INT_MIN;

    for(int i=0;i<row;i++){
        low= min(low,arr[i][0]);
        high= max(high,arr[i][col-1]);
    }

    while(low<=high){
        int mid=(low+high)/2;

        if(countSmallerEqual(arr,mid)<=req){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

int main()
{
  int row = 3, col = 3;
  vector<vector<int>> arr = {{1, 3, 8},
                   {2, 3, 4},
                   {1, 2, 5}};
  cout <<"The median of the row-wise sorted matrix is: "<<Findmedian(arr, row, col) << endl;
  return 0;
}