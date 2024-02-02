// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, 
// and bottom.Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return 
// the length 2 array [i,j].You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
#include<bits/stdc++.h>
using namespace std;

int maxim(vector<vector<int>> &matrix,int col){
        int n=matrix.size();
        int maxi=INT_MIN;
        int maxInd=-1;

        for(int i=0;i<n;i++){
            if(matrix[i][col]>=maxi){
                maxi=matrix[i][col];
                maxInd=i;
            }
        }
        return maxInd;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxInd=maxim(mat,mid);

            int left=mid-1>=0 ? mat[maxInd][mid-1] : -1;
            int right=mid+1<m ? mat[maxInd][mid+1] :-1;
            if(mat[maxInd][mid]>left && mat[maxInd][mid]>right){
                    return {maxInd,mid};
                }
            else if(mat[maxInd][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return {-1,-1};
    }

    int main(){
        vector<vector<int>> matrix={{10,20,15},{21,30,14},{7,16,32}};
        vector<int> ans= findPeakGrid(matrix);

        for(auto it:ans){
            cout<<it<<",";
        }
        return 0;
    }