//Program to print variations of pascal's triangle
#include<bits/stdc++.h>
using namespace std;

//variation 1: To print nth row and rth col element in pascal triangle
// nth row and rth col element in pascal triangle is: (n-1)C(r-1)
int ncr(int n,int r)
{
    int ans=1;
    for(int i=0;i<r;i++)
    {
        ans=ans*(n-i);
        ans=ans/(i+1);
    }
    return ans;
}

//variation 2: To print nth row elements in pascal triangle
void printRow(int n)
{
    int ans=1;
    cout<<"The elements of "<<n<<"th row are: ";
    cout<<ans<<" ";
    
    //printing elements from index 1 to index n-1
    for(int i=1;i<n;i++)
    {
        ans=ans*(n-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
}

//variation 3: to print the entire pascals triangle
//method 1: brute-force approach
// void pascalTriangle(int n)
// {
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             int ans=ncr(i-1,j-1);
//             cout<<ans<<" ";
//         }
//         cout<<endl;
//     }
// }

//method 2: optimal solution
void pascalTriangle(int n)
{
    cout<<"The pascal's triangle elements of "<<n<<" rows are: "<<endl;
    for(int i=1;i<=n;i++)
    {
        int ans=1;
        cout<<ans<<" ";
        for(int j=1;j<i;j++)
        {
            ans=ans*(i-j);
            ans=ans/j;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the row no: ";
    cin>>n;
    int r;
    cout<<"Enter the col no: ";
    cin>>r;

    // cout<<"The element in "<<n<<"th row and "<<r<<"th col is: "<<ncr(n-1,r-1);       //variation 1
    // printRow(n);        //variation 2    
    pascalTriangle(n);     //variation 3

    return 0;
}