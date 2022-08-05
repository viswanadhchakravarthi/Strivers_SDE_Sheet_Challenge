#include<bits/stdc++.h>
struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
};
class Trie{
    private: 
    Node* root;
    public:
    Trie() {
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            // int bit = num & (1<<i); why not working  
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int findMax(int num){
        Node* node = root;
        int res = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)){
                res |= (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return res;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> res(queries.size());
    vector<pair<int,pair<int,int>>> oQ;
    for(int i=0; i<queries.size(); i++){
        oQ.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(oQ.begin(),oQ.end());
    sort(arr.begin(),arr.end());
    
    int j=0, m = arr.size()-1;
    Trie trie;
    
    for(auto &it:oQ){
        while(j<=m and arr[j] <= it.first ){
            trie.insert(arr[j]);
            j++;
        }
        // (j==0) indicates that there's no element in Trie, 
        // if we try to find max it will show segmentation fault
        res[it.second.second] = (j==0)? -1 : trie.findMax(it.second.first);
    }
    return res;
}

// Time : O( Q*32 + N*32 )
