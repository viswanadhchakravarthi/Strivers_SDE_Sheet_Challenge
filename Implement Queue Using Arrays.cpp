#include<bits/stdc++.h>
class Queue {
public:
    vector<int> q;
    Queue() {    }
    
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
       return q.size()==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(q.size()==0)
            return -1;
        int temp = q[0];
        q.erase(q.begin()+0);
        return temp;
    }

    int front() {
        // Implement the front() function
        if(q.size()==0)
            return -1;
        return q[0];
    }
};
