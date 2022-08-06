bool areAnagram(string &str1, string &str2){
    int dict[26]={0};
    for(char i:str1)
        dict[i-'a']++;
    for(char j:str2)
        dict[j-'a']--;
    for(int k=0; k<26; k++)
        if(dict[k]!=0)
            return false;
    return true;
}
// time: (m+n)
// space: O(26)
