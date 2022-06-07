pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
  int xr=0;
	// step1: xor all 1..n natural numbers with 'xr'
  for(int i=1; i<=n ; i++) xr ^= i;
  //step2: xor all array elements with 'xr'
  for(int i=0; i<n ; i++) xr ^= arr[i];
  // rmsb: rightmost set bit of 'xr'
  int rmsb= ( xr & (xr-1)) ^ xr ; 
	// initialising two buckets to divide elements into two groups....!!1
  int buc1=0, buc2=0;
  // separate array elements into two buckets
  for(int i=0 ; i<n ; i++){
        if(arr[i] & rmsb) buc1 ^= arr[i];
        else 			  buc2 ^= arr[i];
    }
  // separate 1..n natural numbers also into those buckets
  // and XOR all elements in individual buckets..
    for(int i=1; i<=n ; i++){
        if(i & rmsb)	buc1 ^= i;
        else 			buc2 ^= i;
    }
    // our assumption is buc1 is Missing num & buc2 is Repeated num
    for(int i=0 ; i<n ; i++){
        if(arr[i]==buc1){
            swap(buc2,buc1); 
        }
    }
    return {buc1,buc2};
}

// Note: This method doesn’t cause overflow, but it doesn’t tell which one occurs twice and which one is missing. We can add one more step that checks which one is missing and which one is repeating by iterating over the array. This can be easily done in O(N) time.

// Time Complexity: O(N) 

// Space Complexity: O(1) As we are NOT USING EXTRA SPACE
