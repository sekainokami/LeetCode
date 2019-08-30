### [208\. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

Difficulty: **Medium**


Implement a trie with `insert`, `search`, and `startsWith` methods.

**Example:**

```
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
```

**Note:**

*   You may assume that all inputs are consist of lowercase letters `a-z`.
*   All inputs are guaranteed to be non-empty strings.


#### Solution

Language: **C++**

```c++
class Trie {
​
private:
    struct Node
    {
        bool is_complete;
        vector<Node*> children;
        Node():is_complete(false),children(26,nullptr){}
    };
    
    Node* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (!curr->children[word[i]-'a'])
            {
                curr->children[word[i]-'a'] = new Node();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->is_complete = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (curr->children[word[i]-'a'] == nullptr)
                return false;
            curr = curr->children[word[i]-'a'];
        }
        
        return curr->is_complete;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Node* curr = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (curr->children[prefix[i]-'a'] == nullptr)
                return false;
            curr = curr->children[prefix[i]-'a'];
        }
        
        return true;
    }
};
​
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
