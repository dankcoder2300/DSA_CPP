// A monkey is given ‘n’ piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. 
//An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
#include<bits/stdc++.h>
using namespace std;

// method 1: using brute force approach
// int findMax(vector<int> &v){
//     int maxi=INT_MIN;
//     int n=v.size();

//     for(int i=0;i<n;i++){
//         if(v[i]>maxi)
//         maxi=v[i];
//     }

//     return maxi;
// }

// int calculateTotalHours(vector<int> &v, int hourly){
//     int totalHours=0;

//     for(int i=0;i<v.size();i++){
//         totalHours+=ceil((double)(v[i])/ (double)(hourly));
//     }

//     return totalHours;
// }

// int minRate(vector<int> &v,int hrs){
//     int maxi=findMax(v);

//     for(int i=1;i<maxi;i++){
//         int time=calculateTotalHours(v,i);

//         if(time<=hrs)
//         return i;
//     }

//     return maxi;
// }

//method 2: using brute force approach
int findMax(vector<int> &v){
    int maxi=INT_MIN;
    int n=v.size();

    for(int i=0;i<n;i++){
        if(v[i]>maxi)
        maxi=v[i];
    }

    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly){
    int totalHours=0;

    for(int i=0;i<v.size();i++){
        totalHours+=ceil((double)(v[i])/ (double)(hourly));
    }

    return totalHours;
}

int minRate(vector<int> &v , int hrs){
    int low=1,high=findMax(v);

    while(low<=high){
        int mid=(low+high)/2;

        int time=calculateTotalHours(v,mid);

        if(time<=hrs){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return low;
}

int main(){
    vector<int> v={7,15,6,3};
    int h=8;
    int ans= minRate(v,h);
    cout<<"Koko should eat atleast "<<ans<<" bananas/hr"<<endl;

    return 0;
}