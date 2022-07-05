string longestCommonPrefix(vector<string> &arr, int n)  // in worst case it will traverse all char's of every len(string)=m , Time: O(n*m) 
{
    string res_str=arr[0];
    int res_len = res_str.length();
    for(int j=1; j<arr.size(); j++)
    {
        for(int i=1; i<=res_len; i++)
            if(res_str[i-1]!=arr[j][i-1])
            {
                res_len = i-1;
                break;
            }
        if(res_len==0)
            return "";
    }
    return res_str.substr(0,res_len);
}


