#include<iostream>
using namespace std;

class TrieNode {
    public:
    TrieNode *children[26];
    bool isTerminal;
    char data;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i = 0;i<25;i++) {
            children[i] = NULL;
        }
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(struct TrieNode *root, string word)
    {
    // base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }
    
    // find the index of that alphabet we're looking for
    int index = word[0] - 'a';
    TrieNode * child; 
    
    // lets check if alphabet at that index is present
    if(root->children[index])
    child = root->children[index];
    
    //If not present we'll create one node and make root's children point
    else {
        child = new TrieNode(word[0]);
        root->children[index] = child;
    }
    insert(child,word.substr(1));
    }
};

int main()
{
    Trie* t = new Trie();
    t->insert(t->root,"abcd");
 return 0;
}