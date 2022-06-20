long double power(long double mid, int n){
   long double ans = 1.0;
   while(n--)
       ans *= mid;
   return ans;
}
long double findNthRootOfM(int n, long long m) {
   long double low = 1.0, high = (long double)m, eps = 1e-9; // eps should be based on the question
   while((high-low)>eps){
       long double mid = (high-low)/2.0 + low;
       if(power(mid,n)>(long double)m)
           high = mid;
       else
           low = mid;
   }
   return low;
}

// Time:  O(n * log2 (m * 10^d ))
// space: O(1)


// Solution2 using inbuilt method:
long double findNthRootOfM(int n, long long m) {
    return pow(m,1.000000/n);
}
// Time:  O(n * log2 (m * 10^d ))
