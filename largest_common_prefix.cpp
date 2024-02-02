// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    sort(strs.begin(), strs.end());
    string first = strs[0], last = strs[strs.size() - 1];
    int low = 0, high = strs[0].size();

    for (int low = 0; low < high; low++)
    {
        if (first[low] == last[low])
        {
            ans = ans + first[low];
        }
        else
            break;
    }
    return ans;
}

int main(){
    vector<string> str ={"club","clumsy","clue","cluster"};

    cout<<"The largest common prefix is: "<<longestCommonPrefix(str)<<endl;

    return 0;
}