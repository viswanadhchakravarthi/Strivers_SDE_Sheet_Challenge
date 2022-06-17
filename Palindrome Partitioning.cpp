#include<bits/stdc++.h>

bool isPalindrome(string &s,int start,int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}

void palin_Partition(string &s,int ind,vector<vector<string>> &res,vector<string> &ds)
{
    if(ind==s.size())
    {   
        res.push_back(ds);
        return;
    }
    for(int i=ind; i<s.size(); i++)
    {
        if(isPalindrome(s,ind,i))
        {
            ds.push_back(s.substr(ind,i-ind+1)); // obj.substr( start_ind, len_of_str_req );
            palin_Partition(s,i+1,res,ds);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> ds;
    palin_Partition(s,0,res,ds);
    return res;
}

    
    
