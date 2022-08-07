string writeAsYouSpeak(int n) 
{
    string res = "1";
    for (int i=1;i<n;i++){
        string tmp = "";
        int count = 1;
        for(int j=0; j<res.size()-1; j++){
            if(res[j]==res[j+1])
                count++;
            else{
                tmp += to_string(count) + res[j];
                count = 1;
            }
        }
        tmp += to_string(count) + res.back();
        res = tmp;
    }
    return res;
}
