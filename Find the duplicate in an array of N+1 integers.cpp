int findDuplicate(vector<int> &nums, int n){
	 // use Tortoise-Hare method( Floyd-Cycle Detection ) used in linked list.
       int slow=nums[0],fast=nums[0];
        do{
            slow= nums[ slow ];
            fast= nums[ nums[fast] ];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
}
// intuition behind this solution is "as there 0 is not present in array definetely some // element might have occupied at nums[0]".
// now nums[nums[0]] will contain some other element except nums[0],
// otherwise we detect duplicates here itself............................
// like this it forms cycle like linked-list .
// so,we have applied Tortoise-Hare method( Floyd-Cycle Detection )

// this works in O(n) Time and O(1) Space and doesn't Modify orginal array given.

// Why we are not using subtraction of 1..n natural numbers from array sum ??
// bcz in question mentioned 1 number repeats , but didn't specify how many times it'll repeat..
// ex: 2 2 2 3 --> here this approach will not work..!!
