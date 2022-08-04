struct Node{
    Node *links[26];
    bool flag = false;
    bool contains(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c,Node* node){
        links[c-'a'] = node;
    }
    Node* nxtNode(char c){
        return links[c-'a'];
    }
    void markEnd(){
        flag = true;
    }
    bool isStrEnded(){
        return flag;
    }
};
class Trie {
private: Node* root;  
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i])){
                node->put(word[i],new Node());
            }
            node = node->nxtNode(word[i]);
        }
        node->markEnd();
    }
    /** Returns if the complete word */
    bool isComplete(string word) {
        Node *node = root;
        bool prevEnds = true;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i]))
                return false;
            node = node->nxtNode(word[i]);
            if(!prevEnds)
                return false;
            prevEnds = node->isStrEnded();
        }
        return prevEnds;
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(int i=0; i<n; i++) 
        obj->insert(a[i]);
    string tmp = "";
    for(int i=0; i<n; i++){
        if(obj->isComplete(a[i])){
               if(a[i].size() > tmp.size())
                   tmp = a[i];
               else if(a[i].size() == tmp.size() and a[i]<tmp)
                   tmp = a[i];
        }
    }
    if(tmp=="") return "None";
    return tmp;
}
// Time: O(n * len) + O(n * len)
// Space: can't predict
