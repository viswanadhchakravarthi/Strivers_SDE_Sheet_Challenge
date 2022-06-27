#include<vector>
#include<algorithm>
void insertSort(stack<int> &stack, int data)
{
    if(stack.empty() or data>stack.top())
    {
        stack.push(data);
        return;
    }
    int tmp = stack.top();
    stack.pop();
    
    insertSort(stack,data);
    
    stack.push(tmp);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty())
        return;
    int tmp=stack.top();
    stack.pop();
    sortStack(stack);
    insertSort(stack,tmp);
}
