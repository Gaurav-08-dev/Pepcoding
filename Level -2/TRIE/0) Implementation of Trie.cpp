/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct  Node
{
    Node* links[26];
    bool flag=false;

    bool conatinsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){flag=true;}

    bool isEnd(){
        return flag;
    }
};

class Trie {

private:
    Node *root;


public:

    /** Initialize your data structure here. */
    Trie() {

        root= new Node();
    }

    /** Inserts a word into the trie. */
    /* TC -> O(N) */
    void insert(string word) {

        Node *node=root;
        for(int i=0;i<word.size();i++){

            if(!node->conatinsKey(word[i])){
                node->put(word[i], new Node());
            }

            // moves to the reference trie
            node=node->get(word[i]);
        }

        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    /*TC-> O(wordlength)*/
    bool search(string word) {
        Node* node=root;

        for(int i=0;i<word.length();i++){
            if(!node->conatinsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }

        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    /* Tc-> O(wordlength) */
    bool startsWith(string word) {

        Node *node= root;
        for(int i=0;i<word.length();i++){

            if(!node->conatinsKey(word[i])){
                return false;
            }

            node=node->get(word[i]);
        }

        return true;
    }
};