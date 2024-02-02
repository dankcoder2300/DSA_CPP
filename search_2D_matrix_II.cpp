// You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows and columns, respectively. 
// The elements of each row and each column are sorted in non-decreasing order.
// But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
// You are given an integer ‘target’, and your task is to find if it exists in the given ‘mat’ or not.
#include<bits/stdc++.h>
using namespace std;

// method 1: using linear serch(brute force approach)
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
//         if(binarySearch(matrix[i],target)==true){
//             return true;
//         }
//     }
//     return false;
// }

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int row=0;
        int col=m-1;

        while(row<n && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}