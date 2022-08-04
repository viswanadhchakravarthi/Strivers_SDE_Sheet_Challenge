/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i]))
                return false;
            node = node->nxtNode(word[i]);
        }
        return node->isStrEnded();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->contains(prefix[i]))
                return false;
            node = node->nxtNode(prefix[i]);
        }
        return true;
    }
};
