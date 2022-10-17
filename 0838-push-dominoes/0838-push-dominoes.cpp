class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        while(true)
        {
        string prev = dominoes;
        for(int i=0;i<dominoes.size();i++)
        {
            if(dominoes[i] == '.' )
            {
               // prev[i] = '.';
                continue;
            }
            
            if(dominoes[i] == 'L')
            {
                if(i>=2)
                {
                    if(dominoes[i-1] == '.' && dominoes[i-2] !='R')
                    {
                        prev[i-1] = 'L';
                    }
                }
                else if(i == 1)
                {
                    if(dominoes[i-1] == '.')
                    {
                        prev[i-1] = 'L';
                    }
                }
            }
            else if(dominoes[i] == 'R')
            {
                
                if(i == dominoes.size()-2)
                {
                    if(dominoes[i+1] == '.')
                    {
                        prev[i+1] = 'R';
                    }
                }
                else if(i < dominoes.size()-2)
                {
                    if(dominoes[i+1] == '.' && dominoes[i+2] !='L')
                    {
                        prev[i+1] = 'R';
                    }
                }
                
            }
            
            //cout<<prev<<endl;
                     
        }
       // cout<<"d"<<endl;
        if(prev == dominoes)
        {
            return dominoes;
        }
        
        dominoes = prev;
        }
        return dominoes;
        
    }
};