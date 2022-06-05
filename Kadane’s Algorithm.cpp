long long maxSubarraySum(int arr[], int n)
{
    long long max_so_far=INT_MIN; // ** very imp to handle all -ve numbers .so, don't make it as 0.
    long long max_ending_here=0;
        
    // if we start looping from i=1 then one we will missed out like [-2,1]
    // if want to start from i=1 then 2nd if must be at start of for loop to avoid wrong results.
       for(int i=0;i<n;i++){
           
           max_ending_here += arr[i];
           
           if(max_ending_here > max_so_far)
               max_so_far = max_ending_here;
           
           // order of these "if" statements is v.v.imp to hanlde all -ve numbers .
           // in case of -ve numbers we r updating max_so_far before assigning max_end_here =0.
           
           if(max_ending_here < 0)
               max_ending_here = 0;
       }
        return (max_so_far<0)? 0 : max_so_far;
}
// here intuition is until now what sum we have calculated should be > 0 to make maximum_sum 
//with upcoming elements ,OtherWise make currentSum as 0 and calculating freshly from next....
// Time : O(n) , Space : O(1)
