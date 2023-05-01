class Solution {
public:
    double average(vector<int>& salary) {
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int sum = 0;
        
        
        for(int i=0;i<salary.size();i++)
        {
            maximum = max(maximum,salary[i]);
            minimum = min(minimum,salary[i]);
            sum += salary[i];
            
        }
        
        
        return ((double)sum - maximum - minimum)/(salary.size() - 2);
    }
};