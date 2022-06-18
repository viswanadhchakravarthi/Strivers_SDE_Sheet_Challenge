#include<algorithm>
void generatePermutations(string s,int i,vector<string> &res)
{
    if(i==s.size())
    {
        res.push_back(s);
        return;
    }
    for(int j=i; j<s.size(); j++)
    {
        string tmp=s;
        swap(tmp[i],tmp[j]);
        generatePermutations(tmp,i+1,res);
    }
    return;
}
vector<string> findPermutations(string &s) {
    vector<string> res;
    sort(s.begin(),s.end());
    generatePermutations(s,0,res);
    return res;
}
// Time Complexity: O(N! X N)

// Space Complexity: O(1)
