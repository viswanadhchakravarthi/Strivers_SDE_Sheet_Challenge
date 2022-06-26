#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2; // s1 is main stack , s2 is tmp stack 
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(s1.empty())
            return -1;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int front_ele = s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return front_ele;
    }

    int peek() {
        // Implement the peek() function here.
        if(s1.empty())
            return -1;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int front_ele = s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return front_ele;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};
