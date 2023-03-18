class BrowserHistory {
public:
    
    vector<string> v;
    int curr;
    int end;
    BrowserHistory(string homepage) {
        
        v=vector<string>(1000);
        curr=0;
        v[curr] = homepage;
        end = 0;
        
    }
    
    void visit(string url) {
        
        if(curr == end)
        {
           curr++;
           end++;
        }
        else
        {
            curr++;
            end = curr;
        }
        v[curr] = url;
        
    }
    
    string back(int steps) {
        
        if(steps > curr)
        {
            curr = 0;
        }
        else
        {
            curr = curr - steps;
        }
        return v[curr];
        
    }
    
    string forward(int steps) {
        
        int possible = end - curr;
        //cout<<curr<<" "<<end<<" "<<possible<<endl;
        if(steps > possible)
        {
            curr = end;
        }
        else
        {
            curr = curr + steps;
        }
        
        return v[curr];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */