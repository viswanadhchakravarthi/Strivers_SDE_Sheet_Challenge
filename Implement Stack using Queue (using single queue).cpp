#include<queue>
class Stack {
	// Define the data members.
   queue<int> prim,secon;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return prim.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return prim.empty();
    }

    void push(int element) {
        // Implement the push() function.
        prim.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(prim.size()==0)
            return -1;
        while(prim.size()!=1)
        {
            secon.push(prim.front());
            prim.pop();
        }
        int top_ele=prim.front();
        prim.pop();
        swap(secon,prim);
        return top_ele;
    }

    int top() {
        // Implement the top() function.
        if(prim.size()==0)
            return -1;
        int top_ele;
        while(prim.size()!=0)
        {
            secon.push(prim.front());
            top_ele = prim.front();
            prim.pop();
        }
        swap(secon,prim);
        return top_ele;
    }
};
