//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool StartsWith(struct TrieNode *, string);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        // for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;
for (int i = 0; i < n; i++) insert(root, keys[i]);
        cin >> abc;
        // Search for different keys

        if (StartsWith(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/



//Function to use TRIE data structure and search the given string.
void insert(struct TrieNode *root, string key)
{
    // code here
    if(key.length() == 0) {
        root->isLeaf = true;
        return;
    }
    
    int index = key[0]-'a';
    struct TrieNode *child;
    //if word is present
    if(root->children[index] != NULL)
    child = root->children[index];
    //word is not present
    else {
        child = new TrieNode();
        root->children[index] = child;
    }
    
    //call recursion
    insert(child,key.substr(1));
}

bool StartsWith(struct TrieNode *root, string key) 
{
    // code here
    if(key.length() == 0) {
        return true;
    }
    
    int index = key[0]-'a';
    struct TrieNode *child;
    //if word is present
    if(root->children[index] != NULL)
    child = root->children[index];
    //word is not present
    else {
        return false;
    }
    
    //call recursion
    return StartsWith(child,key.substr(1));
}