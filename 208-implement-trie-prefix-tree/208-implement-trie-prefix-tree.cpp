class TrieNode {
public:
    char c;    
    std::vector<std::shared_ptr<TrieNode>> children;
    bool isEnd;
    
    TrieNode() : c(' '), isEnd(false){
        
    }
    
    TrieNode(char ch, bool isEnd): c(ch), isEnd(isEnd){
    }
};

class Trie {
private:
    std::shared_ptr<TrieNode> root = std::make_shared<TrieNode>();
    
public:
    Trie(){
    }
    
    void insert(string word) {
        TrieNode* ptr = root.get();
        for(char c : word){
            bool found = false;
            for(std::shared_ptr<TrieNode> node : ptr->children){
                if(node.get()->c == c){
                    ptr = node.get();
                    found = true;
                    break;
                }
            }
            if(!found){
                std::shared_ptr<TrieNode> newNode = std::make_shared<TrieNode>(c, false);
                ptr->children.push_back(newNode);
                ptr = newNode.get();
            } 
        }
        
        ptr->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode* ptr = root.get();
        for(char c : word){
            // look in children for c
            bool found = false;
            for(std::shared_ptr<TrieNode> node : ptr->children){
                if(node.get()->c == c){
                    ptr = node.get();
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
        TrieNode* ptr = root.get();
        for(char c : prefix){
            // look in children for c
            bool found = false;
            for(std::shared_ptr<TrieNode> node : ptr->children){
                if(node.get()->c == c){
                    ptr = node.get();
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