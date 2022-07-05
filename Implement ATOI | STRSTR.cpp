int atoi(string str) {
    int sign= str[0]=='-'? -1:1,num=0;
    for(char c:str)
        if('0'<=c && c<='9')
            num = (num*10) + (c-'0');
    if(sign==-1)
        num *= -1;
    return num;
}
