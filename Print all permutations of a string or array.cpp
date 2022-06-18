#include<algorithm>
void generatePermutations(string &s, int i, vector<string> &res)
{
    if(i==s.size())
    {
        res.push_back(s);
        return;
    }
    for(int j=i; j<s.size(); j++)
    {
        swap(s[i],s[j]);
        generatePermutations(s,i+1,res);
        swap(s[i],s[j]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string> res;
    sort(s.begin(),s.end());
    generatePermutations(s,0,res);
    return res;
}
// Time Complexity: O(N! X N)

// Space Complexity: O(1)
