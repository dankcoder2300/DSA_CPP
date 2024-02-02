// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the 
// number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
#include<bits/stdc++.h>
using namespace std;

//method 1: using unordered map and priority queue
string func(char ch,int freq){
    string ans="";
    for(int i=0;i<freq;i++)
    {
        ans+=ch;
    }
    return ans;
}

string sortCharacter(string str)
{
    unordered_map<char,int> mp;

    for(auto it:str){
        mp[it]++;
    }

    priority_queue<pair<int,char>> pq;

    for(auto it:mp){
        pq.push({it.second,it.first});
    }

    string ans="";

    while(!pq.empty()){
        int freq=pq.top().first;
        char ch=pq.top().second;

        ans+=func(ch,freq);

        pq.pop();
    }

    return ans;
}


int main()
{
    string str;
    cout<<"Enter the string: "<<endl;
    cin>>str;
    
    cout<<sortCharacter(str)<<endl;

    return 0;
}