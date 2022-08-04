struct Node{
    private:
    Node *links[26];
    int flag = 0; // to repr end of a word
    int wordcount = 0; // to countWords w.r.t that node
    public:
    bool contains(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c,Node *node){
        links[c-'a'] = node;
    }
    Node* nxtNode(char c){
        return links[c-'a'];
    }
    void markEnd(){
        flag++;
    }
    int getFlag(){
        return flag;
    }
    void removeWord(){
        flag--;
    }
    void incWordCount(){
        wordcount++;
    }
    int getWordCount(){
        return wordcount;
    }
    void decWordCount(){
        wordcount--;
    }
};
class Trie{
    private: Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i]))
                node->put(word[i],new Node());
            node = node->nxtNode(word[i]);
            node->incWordCount();
        }
        node->markEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i]))
                return 0;
            node = node->nxtNode(word[i]);
        }
        return node->getFlag();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i]))
                return 0;
            node = node->nxtNode(word[i]);
        }
        return node->getWordCount();
    }

    void erase(string &word){
        stack<Node*> st;
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i]))
                return;
            
            node = node->nxtNode(word[i]);  
            node->decWordCount();
        }
        node->removeWord();
    }
};
