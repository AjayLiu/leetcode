class TrieNode {
public:
    char c;    
    std::vector<TrieNode*> children;
    bool isEnd;
    
    TrieNode() : c(' '), isEnd(false){
        
    }
    
    TrieNode(char ch, bool isEnd): c(ch), isEnd(isEnd){
    }
};

class Trie {
private:
    TrieNode* root = new TrieNode();
    
public:
    Trie(){
    }
    
    void insert(string word) {
        TrieNode* ptr = root;
        char currentChar;
        for(char c : word){
            bool found = false;
            currentChar = c;
            for(TrieNode* node : ptr->children){
                if(node->c == c){
                    ptr = node;
                    found = true;
                    break;
                }
            }
            if(!found){
                TrieNode* newNode = new TrieNode(currentChar, false);
                ptr->children.push_back(newNode);
                ptr = newNode;
            } 
        }
        
        ptr->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode* ptr = root;
        for(char c : word){
            // look in children for c
            bool found = false;
            for(TrieNode* node : ptr->children){
                if(node->c == c){
                    ptr = node;
                    found = true;
                    break;
                }
            }
            if(!found)
                return false;
        }
        return ptr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(char c : prefix){
            // look in children for c
            bool found = false;
            for(TrieNode* node : ptr->children){
                if(node->c == c){
                    ptr = node;
                    found = true;
                    break;
                }
            }
            if(!found)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */