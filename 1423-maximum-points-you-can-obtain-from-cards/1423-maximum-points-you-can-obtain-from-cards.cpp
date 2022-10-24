class Solution {
public:
    
    //Sliding window taking k cards from end means  u need to minimize n-k length subrray
    
    
    int maxScore(vector<int>& cardPoints, int k) 
    {
        
        int totalPoints = 0;
        
        for(int i=0;i<cardPoints.size();i++)
        {
            totalPoints += cardPoints[i];
        }
        
        int WindowSum = 0;
        
        for(int i=0;i < (cardPoints.size() - k) ; i++)
        {
            
            WindowSum += cardPoints[i];
            
        }
        
        int minimum = WindowSum;
        int len = cardPoints.size() - k ; 
        
        
        for(int i = (cardPoints.size() - k) ; i< cardPoints.size();i++)
        {
            
            WindowSum = WindowSum - cardPoints[i - len] + cardPoints[i];
            
            minimum = min(WindowSum,minimum);
            
            
        }
   
        return totalPoints - minimum;
    }
};