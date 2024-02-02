/*You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be
shipped within ‘d’ days.The weights of the packages are given in an array ‘of weights’. The packages are loaded on the conveyor 
belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of 
the ship.Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.*/
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int findDays(vector<int> &weights, int capacity){
//     int load=0;
//     int days=1;

//     for(int i=0;i<weights.size();i++){
//         if(load+weights[i]>capacity){
//             days+=1;
//             load=weights[i];
//         }
//         else{
//             load+=weights[i];
//         }
//     }
//     return days;
// }

// int leastWeightCapacity(vector<int> &weights, int d){
    
//     for(int i=*max_element(weights.begin(),weights.end());i<=accumulate(weights.begin(),weights.end(),0);i++){
//         if(findDays(weights,i)<=d){
//             return i;
//         }
//     }

//     return -1;
// }

//method 2: using binary search (optimal approach)
int findDays(vector<int> &weights, int capacity){
    int load=0;
    int days=1;

    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>capacity){
            days+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    int ans=-1;

    while(low<=high){

        int mid=(low+high)/2;

        if(findDays(weights,mid)<=d){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}