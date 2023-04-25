class SmallestInfiniteSet {
public:
    vector<int> v;
    SmallestInfiniteSet() {
        for(int i=0;i<=1000;i++)
        {
            v.push_back(i);
        }
    }
    
    int popSmallest() {
        
        for(int i=1;i<=1000;i++)
        {
            if(v[i] == i)
            {
                v[i] = -1;
                return i;
            }
        }
        
        return -1;
    }
    
    void addBack(int num) {
        
        v[num] = num;
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */