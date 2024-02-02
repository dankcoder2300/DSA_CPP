//Program to rotate matrix by 90 degree
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force approach
// vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int n, int m)
// {
//     vector<vector<int>> ans(n,vector<int> (n,0));

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             ans[i][j]=matrix[n-j-1][i];     //rotation by 90 deg clockwise
//         }
//     }
//     return ans;
// }

// method 2: transposing the matrix and the reversing each row (optimal approach)
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reversing each row
    for(int i=0;i<n;i++)
    {
    reverse(matrix[i].begin(),matrix[i].end());
    }

    return matrix;
}

int main()
{
    int n;
    cout<<"Enter the no of row: ";
    cin>>n;
    int m;
    cout<<"Enter the no of columns: ";
    cin>>m;

    vector<vector<int>> matrix;
    cout<<"Enter the elements of matrix: ";
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    vector<vector<int>> ans=rotateMatrix(matrix,n,m);
    for(auto it:ans)
    {
        for(auto itt:it)
        {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}