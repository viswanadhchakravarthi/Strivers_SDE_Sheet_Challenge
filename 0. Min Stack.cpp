// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> st,mini;
    public:
		
		// Constructor
		minStack() {    
        }
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			st.push(num);
            int prev = 1e9;
            if(!mini.empty())
                prev = mini.top();
            mini.push(min(num,prev));
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty())
                return -1;
            int tmp = st.top();
            st.pop();
            mini.pop();
            return tmp;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty())
                return -1;
            int tmp = st.top();
            return tmp;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(mini.empty())
                return -1;
            return mini.top();
		}
};
