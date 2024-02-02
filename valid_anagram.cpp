// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the 
// original letters exactly once.
#include<bits/stdc++.h>
using namespace std;

// method 1:using counter method
// bool isAnagram(string s, string t) {

//         if(s.size()!=t.size())
//         return false;
        
//         int arr[26];
//         for(auto it:s){
//             arr[it-'a']++;
//         }
//         for(auto it:t)
//         {
//             arr[it-'a']--;
//             if(arr[it-'a']<0)
//             return false;
//         }

//         return true;
//     }

// method 2: using sort function
bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
        return false;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t)
        return true;

        return false;
}


int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;

    bool ans=isAnagram(s,t);

    if(ans==1)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;

    return 0;
}