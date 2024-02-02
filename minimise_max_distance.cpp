// You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. 
// You are also given an integer ‘k’. You have to place ‘k’ new gas stations on the X-axis. You can place them anywhere on the 
// non-negative side of the X-axis, even on non-integer positions. Let ‘dist’ be the maximum value of the distance between adjacent 
// gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.
#include<bits/stdc++.h>
using namespace std;

//method 1: using linear search(brute force method)
// long double minimiseMaxDistance(vector<int> &arr,int k){
//     int n=arr.size();

//     vector<int> howMany(n-1,0);

//     for(int gasStations=1;gasStations<=k;gasStations++){
//         long double maxSection=-1;
//         int maxInd=-1;

//         for(int i=0;i<n-1;i++){
//             long double diff=arr[i+1]-arr[i];
//             long double sectionLength=diff/(long double)(howMany[i]+1);
            
//             if(sectionLength>maxSection){
//                 maxSection=sectionLength;
//                 maxInd=i;
//             }
//         }
//         howMany[maxInd]++;
//     }

//     long double maxAns=-1;

//     for(int i=0;i<n-1;i++){
//         long double diff=arr[i+1]-arr[i];
//         long double sectionLength=diff/(long double)(howMany[i]+1);

//         maxAns= max(sectionLength,maxAns);
//     }

//     return maxAns;
// }

//method 2: using priority queue(heap) (better approch)
// long double minimiseMaxDistance(vector<int> &arr,int k){
//     int n=arr.size();
//     vector<int> howMany(n-1,0);

//     priority_queue<pair<long double,int>> pq;

//     for(int i=0;i<n-1;i++){
//         long double diff=arr[i+1]-arr[i];
//         pq.push({diff,i});
//     }

//     for(int gasStations=1;gasStations<=k;gasStations++){
//         auto top=pq.top();
//         pq.pop();
        
//         int sectionInd=top.second;

//         howMany[sectionInd]++;

//         long double initialDiff=arr[sectionInd+1]-arr[sectionInd];
//         long double newSectionLen=initialDiff/(long double)(howMany[sectionInd]+1);

//         pq.push({newSectionLen,sectionInd});
//     }

//     return pq.top().first;
// }

//method 3: using binary search(optimal approach)                      will prefer method 2 bcoz its easier
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}