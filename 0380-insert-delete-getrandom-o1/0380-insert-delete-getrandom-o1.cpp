class RandomizedSet {
public:
    
    vector<int>v;
    unordered_map<int,bool>mp;
    RandomizedSet() 
    {
       //no code	
    }
    bool insert(int val) 
    {
       if(mp[val] == false)       //freq nahi mili mtlb not present in vector and mp
       {
          mp[val]=true;
          v.push_back(val);       	
          return true;           //element has been inserted
       }
       else if(mp[val]==true)    //element cannot be inserted it was already present
       {
          return false;
       }
        return false;
    }
    bool remove(int val) 
    {
       if(mp[val]==true)   //the item was present now it has be
       {
          mp.erase(val);
          v.erase(find(v.begin(),v.end(),val));
          return true;
       }
       else
       {
        return false;    //the item is not present
       }
        return false;
    }
    int getRandom() 
    {
        return v[rand()%v.size()];        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */