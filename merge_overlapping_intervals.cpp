//Program to Merge Overlapping Sub-intervals
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force approach
// vector<vector<int>> merge_overlap(vector<vector<int>> &arr) {
//     int n=arr.size();
//     vector<vector<int>> ans;
//     sort(arr.begin(), arr.end());

//     for (int i = 0; i < n; i++) 
//     {
//         int start = arr[i][0];
//         int end = arr[i][1];

//         if (!ans.empty() && end <= ans.back()[1]) // corrected condition
//         {
//             continue;
//         }
//         // checks the rest of intervals
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j][0] <= end)
//             {
//                 end = max(end, arr[j][1]);
//             }
//             else
//             {
//             break;
//             }
//         }

//         ans.push_back({start, end});
//     }

//     return ans;
// }

// method 2: optimal approch
vector<vector<int>> merge_overlap(vector<vector<int>> arr)
{
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
    {
        if(ans.empty() || arr[i][0]>ans.back()[1])
        ans.push_back(arr[i]);

        else
        ans.back()[1]=max(ans.back()[1],arr[i][1]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = merge_overlap(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
