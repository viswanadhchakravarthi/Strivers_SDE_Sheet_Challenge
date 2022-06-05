void sort012(int *arr, int n)
{
   int low=0,mid=0,high=n-1;
        while(mid <= high){
            switch(arr[mid]){
                case 0:
                    swap(arr[low],arr[mid]); 
                    mid++;
                    low++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr[high],arr[mid]);
                    high--;
                    break;
            }
        }
}
// here intuition is 3-Pointer approach 
// Time : O(n) & single traversal
