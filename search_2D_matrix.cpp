// You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows and columns, respectively. 
// The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last 
// element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the 
// given ‘mat’ or not.
#include<bits/stdc++.h>
using namespace std;

//method 1: using linear serch(brute force approach)
// bool searchMatrix(vector<vector<int>> &matrix,int x){
//     int n=matrix.size();
//     int m=matrix[0].size();

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]==x){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//method 2: using binary search(better approach)
// bool binarySearch(vector<int> &matrix,int target){
//     int n=matrix.size();
//     int low=0;
//     int high=matrix.size()-1;

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(matrix[mid]==target){
//             return true;
//         }
//         else if(matrix[mid]<target){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return false;
// }

// bool searchMatrix(vector<vector<int>> &matrix, int target){
//     int n= matrix.size();
//     int m= matrix[0].size();

//     for(int i=0;i<n;i++){
//         if(matrix[i][0]<=target && target<=matrix[i][m-1]){
//             return binarySearch(matrix[i],target);
//         }
//     }
//     return false;
// }

//method 3: using binary search(optimal approach)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=m*n-1;

        while(low<=high){
            int mid=(low+high)/2;

            int row=mid/m;
            int col=mid%m;

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}