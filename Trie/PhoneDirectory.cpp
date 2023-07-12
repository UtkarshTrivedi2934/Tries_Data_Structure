//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    class Trienode
{
   public:
       char data;
       bool isTerminal;
       int count;
       Trienode *children[26];
   
   Trienode(char ch)
   {
       data = ch;
       isTerminal = false;
       count =0;
       for(int i=0;i<26;i++)
           children[i]=NULL;
   }
};

class Trie{
   public:
       Trienode *root;
       
       Trie()
       {
           root = new Trienode('\0');
       }
   
   
       void insertutil(Trienode *root,string str)
       {
           if(str.length()==0)
           {
               root->isTerminal = true;
               return;
           }
           
           int index = str[0]-'a';
           Trienode *temp;
           
           if(root->children[index]!=NULL)
           {
               temp = root->children[index];
           }
           else
           {
               temp = new Trienode(str[0]);
               root->children[index]=temp;
           }
           
           insertutil(temp,str.substr(1));
       }
       void insert(string str)
       {
           insertutil(root,str);
       }
   
   void printsugg(Trienode *curr,string &prefix,vector<string> &temp)
{
   if(curr->isTerminal)
   {
       temp.push_back(prefix);
   }
   
   for(char ch='a';ch<='z';ch++)
   {
       Trienode *next = curr->children[ch-'a'];
       
       if(next!=NULL)
       {
           prefix.push_back(ch);
           printsugg(next,prefix,temp);
            prefix.pop_back();
       }
   }
}
vector<vector<string>> getSuggestion(string str)
{
   vector<vector<string>> output;
   Trienode* prev = root;
   string prefix = "";
   
   for(int i=0;i<str.length();i++)
   {
       char lastch = str[i];
       prefix.push_back(lastch);
       
       Trienode *curr = prev->children[lastch-'a'];
       
       if(curr==NULL)
           break;
       
       vector<string> temp;
       
       printsugg(curr,prefix,temp);
       
       output.push_back(temp);

       prev = curr;
   }
   
   return output;
}
};
   vector<vector<string>> displayContacts(int n, string contact[], string s)
   {
        Trie *t = new Trie();
       for(int i=0;i<n;i++)
   {
       t->insert(contact[i]);
   }
   
   vector<vector<string>> ans= t->getSuggestion(s);
   
   if(ans.size() == s.size()) return ans;
       else{
           int diff = s.size() - ans.size();
           for(int i=0; i<diff; i++){
               ans.push_back({"0"});
           }
           return ans;
       // code here
   }
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends