class MinStack {
public:
    vector<int> v;
    int minimum;
    int freq;
    MinStack() {
        minimum=INT_MAX;
        freq=0;
    }
    
    void push(int val) 
    {
        if(val < minimum)
        {
            minimum=val;
            freq=1;
        }
        else if(val == minimum)
        {
            freq++;
        }
        v.push_back(val);
        
    }
    
    void pop() 
    {
        if(v[v.size()-1] == minimum)
        {
            freq--;
        }
        v.pop_back();
       
        if(freq == 0)
        {
            minimum=INT_MAX;
            freq=0;
            for(int i=0;i<v.size();i++)
            {
                minimum = min(minimum,v[i]);
            }
            
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==minimum)
                {
                    freq++;
                }
            }
        }
        
    }
    
    int top() 
    {
        
        return v[v.size()-1];
    }
    
    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */