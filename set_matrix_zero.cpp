//Program to  set the matrix entire column and row to 0 if its element is 0
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force appraoch
// void markRow(vector<vector<int>> &matrix,int n,int m, int i)
// {
//     for(int j=0;j<m;j++)
//     {
//         if(matrix[i][j]!=0)
//         matrix[i][j]=-1;
//     }
// }
// void markCol(vector<vector<int>> &matrix,int n,int m, int j)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(matrix[i][j]!=0)
//         matrix[i][j]=-1;
//     }
// }

// vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix,int n, int m)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 markRow(matrix,n,m,i);
//                 markCol(matrix,n,m,j);
//             }
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==-1)
//             {
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     return matrix;
// }

//method 2: better approach
// vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix, int n,int m)
// {
//     int row[n]={0};
//     int col[m]={0};

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 row[i]=1;
//                 col[j]=1;
//             }
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(row[i] || col[j])
//             {
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     return matrix;
// }

//method 3: optimal approach(improving space complexity)
vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix, int n, int m)
{
    int col0=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                //mark ith row
                matrix[i][0]=0;

                if(j!=0)
                {
                    //mark jth col
                    matrix[0][j]=0;
                }
                else
                {
                    col0=0;
                }
            }
        }
    }

    //mark 0 from index[1,1] to index[n-1,m-1]
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(matrix[i][j]!=0)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
            {
                matrix[i][j]=0;
            }
            }
        }
    }

    //finally mark the first row and first col elements
    if(matrix[0][0]==0)
    {
        for(int j=0;j<m;j++)
        matrix[0][j]=0;
    }
    if(col0==0)
    {
        for(int i=0;i<n;i++)
        matrix[i][0]=0;
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
    vector<vector<int>> ans=setMatrixZero(matrix,m,n);
    cout<<"\nThe matrix after setting to zero is:\n";
    for(auto it:ans)
    {
        for(auto itt:it)
        {
        cout<<itt<<" ";
        }
        cout<<endl;
    }
}