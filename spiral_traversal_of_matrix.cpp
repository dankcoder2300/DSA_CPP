//Program to print matrix in spiral form
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> ans;

    int left=0,top=0, right=m-1,bottom=n-1;
    
    while(left<=right && top<=bottom)
    {
        //printing left to right
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        //printing from top to bottom
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        //printing from right to left
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        //printing from bottom to top
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
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

    vector<int> ans=spiralMatrix(matrix,n,m);
    cout<<"Spiral form of matrix is: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}