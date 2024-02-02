/*You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// bool canPlaceCows(vector<int> &stalls, int distance, int cows){
//     int cntCows=1;
//     int lastCow=stalls[0];

//     for(int i=1;i<stalls.size();i++){
//         if(stalls[i]-lastCow>=distance){
//             cntCows++;
//             lastCow=stalls[i];
//         }
//     }
//     if(cntCows>=cows){
//         return true;
//     }

//     return false;
// }

// int aggressiveCows(vector<int> &stalls, int k){
//     sort(stalls.begin(),stalls.end());
//     int limit=stalls[stalls.size()]-stalls[0];

//     for(int i=1;i<=limit;i++){
//         if(canPlaceCows(stalls,i,k)==false){
//             return (i-1);
//         }
//     }
//     return limit;
// }

//method 2: using binary search(optimal approach)
bool canPlaceCows(vector<int> &stalls, int distance, int cows){
    int cntCows=1;
    int lastCow=stalls[0];

    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-lastCow>=distance){
            cntCows++;
            lastCow=stalls[i];
        }
    }
    if(cntCows>=cows){
        return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    sort(stalls.begin(),stalls.end());

    int low=stalls[0],high=stalls[stalls.size()-1];
    int ans=stalls[stalls.size()-1,stalls[0]];

    while(low<=high){
        int mid=(low+high)/2;

        if(canPlaceCows(stalls,mid,cows)==true){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}