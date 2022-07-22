class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    Kthlargest(int k, vector<int> &arr) {
//        priority_queue<int,vector<int>,greater<int>> tmp(arr.begin(),arr.end()); --> failed
//        minHeap = tmp;
        for(int i:arr) minHeap.push(i);
    }

    void add(int num) {
        minHeap.push(num);
        minHeap.pop();
    }

    int getKthLargest() {
       return minHeap.top();
    }

};
