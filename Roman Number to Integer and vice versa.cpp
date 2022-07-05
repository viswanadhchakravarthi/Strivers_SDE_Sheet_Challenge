#include<bits/stdc++.h>
int romanToInt(string s) { // Time: O(#characters_in_string)
    int n=s.length();
    unordered_map<char,int> um
    {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    vector<int> v;    
    for(char c:s)
        v.push_back(um[c]);
    int sum=0;
    for(int i=0; i<n; i++)
        if(i<n-1 && um[s[i]]<um[s[i+1]])
            sum -= um[s[i]];
        else
            sum += um[s[i]];
    return sum;
}

string intToRoman(int num) { // Time: O(1) bcz num is always <3999
        string Unit[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string Ten[] ={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string Hund[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string Thou[]={"","M","MM","MMM"};
        
        
        return Thou[num/1000]+Hund[(num%1000)/100]+Ten[(num%100)/10]+Unit[(num%10)];
}
