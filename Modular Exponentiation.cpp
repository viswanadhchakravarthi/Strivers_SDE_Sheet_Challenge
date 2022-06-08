int modularExponentiation(int x, int n, int m) {
	// Range of Int : -2,147,483,648 to 2,147,483,647
    long long ans = 1;
    x = x % m;
    // Edge Case bcz if (-2,147,483,648*-1) stored in INT , it gets overflown.
    // So store in Long Long
    while( n > 0){
        if( n % 2 == 0){
            x = (1LL * x * x) % m;
            n = n >> 1;
        }   
        else{
            ans = (1LL * ans * x ) % m;
            n = n - 1;
        }
    }
    return (int)ans;
}
