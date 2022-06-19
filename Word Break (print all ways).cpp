#include<bits/stdc++.h>
bool _find(string tmp, vector<string> &dictionary)
{
    for(string st:dictionary)
    {
        if(tmp==st)
            return true;
    }
    return false;
}
int char_count(string str)
{
    int count = 0;
    for(int i=0; i<str.size(); i++)
        if(str[i] != ' ')
            count++;
    return count;
}
void solve(string &s,int i, vector<string> &dictionary,string tmp,vector<string> &ans,string possib)
{
    if(i==s.size())
    {
        int count_s = char_count(s);
        int count_possib = char_count(possib);
        if(possib.size()>=s.size() && count_s == count_possib)
            ans.push_back(possib);
        return;
    }
    
    tmp += s[i];
    if(_find(tmp,dictionary))
    {
        solve(s,i+1,dictionary,"",ans, possib +tmp+ " ");
    }
    solve(s,i+1,dictionary,tmp,ans, possib);
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string tmp = "";
    solve(s,0,dictionary,"",ans,"");
    return ans;
}
