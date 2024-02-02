// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
#include<bits/stdc++.h>
using namespace std;

 bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
        return false;

        string str=s+s;
        if(str.find(goal)!=-1)
        return true;

        return false;
}

int main()
{
    string s;
    cin>>s;
    string goal;
    cin>>goal;

    bool ans=rotateString(s,goal);

    if(ans==1)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;

    return 0;
}