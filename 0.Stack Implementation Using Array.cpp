// Stack class.
class Stack {
    
public:
    vector<int> v;
    int capacity;
    Stack(int capacity) {
        this->capacity = capacity;
    }

    void push(int num) {
        if(capacity!=v.size())
            v.push_back(num);
    }

    int pop() {
        if(v.size()==0)
            return -1;
        int tmp = v.back();
        v.pop_back();
        return tmp;
    }
    
    int top() {
        if(v.size()==0)
            return -1;
        return v.back();
    }
    
    int isEmpty() {
        if(v.size()==0)
            return 1;
        return 0;
    }
    
    int isFull() {
        if(capacity==v.size())
            return 1;
        return 0;
    }
    
};
