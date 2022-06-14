//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int calculateMinPatforms(int arr[], int dep[], int n) {
    // Pairs cannot be together. Thats the problem. Just think yourself as a station master, 
        // and you just care how many came and how many went. Not when one came and when went
    sort(arr,arr+n);
    sort(dep,dep+n);
    int plat_needed=1, result=1;
    // atleast one train will occupy plat, so starting from start_ind( i ) = 1 
    int i=1,j=0; 
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) // train_arrival
        {
            plat_needed++;
            i++;
        }
        else // train_departure
        {
            plat_needed--;
            j++;
        }
        if(plat_needed > result)
            result = plat_needed;
    }
    return result;
}
//     Time: O(nlogn) for sorting
//     space: O(1)
