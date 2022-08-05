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
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(auto &it1:arr1) trie.insert(it1);
    
    int maxi = 0;
    for(auto &it2:arr2) 
        maxi = max( maxi, trie.findMax(it2));
    return maxi;
}
