// You have been given a non-empty grid ‘mat’ with ‘n’ rows and ‘m’ columns consisting of only 0s and 1s. All the rows are sorted 
// in ascending order.
// Your task is to find the index of the row with the maximum number of ones.
// Note: If two rows have the same number of ones, consider the one with a smaller index. If there’s no row with at 
// least 1 zero, return -1.
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int rowWithMax1s(vector<vector<int>> &matrix,int n, int m){
//     int maxCnt=0;
//     int index=-1;

//     for(int i=0;i<n;i++){
//         int cntOne=0;
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]==1){
//                 cntOne++;
//             }
//         }
//         if(cntOne>=maxCnt){
//             maxCnt=cntOne;
//             index=i;
//         }
//     }

//     return index;
// }

//method 2: using lower bound and binary search(optimal method) 
int lowerBound(vector<int> &matrix,int n, int x){
    int low=0;
    int high=n-1;
    int ans=0;

    while(low<=high){
        int mid=(low+high)/2;

        if(matrix[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> matrix, int n, int m){
    int cntOne=0;
    int maxCnt=0;
    int index=-1;

    for(int i=0;i<n;i++){
        cntOne=m-lowerBound(matrix[i],m,1);

        if(cntOne>maxCnt){
            maxCnt=cntOne;
            index=i;
        }
    }

    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<rowWithMax1s(matrix, n, m) << '\n';
}