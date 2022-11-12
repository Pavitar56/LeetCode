class LRUCache {

    private:
    
    class Node          //least recently used is at end and most recently used is at front
    {
        public:
        
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int k,int v)
        {
            
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
            
        
        
    };
    
    
    unordered_map<int,Node*> map;
    Node* head;   //2 dummy nodes in order to avoid checking for null
    Node* tail;
    
    int size;
    int cap;
    
    
    
    
    void insertNode(Node* curr)
    {
        
        head->next->prev = curr;
        curr->next = head->next;
        curr->prev = head;
        head->next=curr;
            
    }
    
    void delNode(Node* curr)
    {
        curr->prev->next = curr ->next;
        curr->next->prev = curr->prev;
        
        //delete curr;
        
    }
    
    public:
        
    LRUCache(int capacity) 
    {
        size = 0;
        cap = capacity;
        
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        
        head->next = tail;
        head->prev = NULL;
        
        tail->prev=head;
        tail->next = NULL;
    }
    
    int get(int key) 
    {
        
        if(map.count(key) == 0)
        {
            return -1;
        }
        
        Node* curr = map[key];
        
        delNode(curr);
        insertNode(curr);
        
        return curr->val;
    }
    
    void put(int key, int value)
    {
        
        if(map.count(key) > 0)
        {
            map[key] -> val = value;
            delNode(map[key]);
            insertNode(map[key]);
            
            return;
        }
        
        
        if(size < cap)
        {
            Node* newNode = new Node(key,value);
            insertNode(newNode);
            
            map[key] = newNode;
            
            size++;  //only increase size here
            return ;
        }
        
        map.erase(tail->prev->key);    //careful size DOESNOT increase as this is the first time when we                                                              //      are actually deleting node          
        delNode(tail->prev);
       
        
        Node* newNode = new Node(key,value);
        insertNode(newNode);
        
        map[key] = newNode;
        
        
        
        return;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */