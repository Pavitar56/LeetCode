class TrieNode
{
    public:
 
    char data;
    bool isTerminal;
    vector<TrieNode*> children;
    
    TrieNode(char c)
    {
        data=c;
        children = vector<TrieNode*>(26,NULL);
        isTerminal=false;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() 
    {
        root = new TrieNode('\0');
    }
    
    void insert(string word) 
    {
       TrieNode* temp = root;
    
        for(int i=0;i<word.size();i++)
        {
            int index = word[i]  - 'a';
            
            if(temp->children[index] == NULL)
            {
                temp->children[index] = new TrieNode(word[i]);
            }
            
            
//             if(i==(word.size()-1))
//             {
//                 temp->children[index]->isTerminal = true;
//             }
            
            temp = temp->children[index];
        }
        
        temp->isTerminal = true;
    }
    
    bool search(string word) 
    {
        TrieNode* temp = root;
    
        for(int i=0;i<word.size();i++)
        {
            int index = word[i]  - 'a';
           
            if(temp->children[index] == NULL)
            {
                return false;
            }
            
            
//             if(i==(word.size()-1))
//             {
//                 if(temp->children[index]->isTerminal == false)
//                 {
//                     return false;
//                 }
//             }
            
            temp = temp->children[index];
           
        }
        
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* temp = root;
    
        for(int i=0;i<prefix.size();i++)
        {
            int index = prefix[i]  - 'a';
            
            if(temp->children[index] == NULL)
            {
                return false;
            }
            temp = temp->children[index];
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