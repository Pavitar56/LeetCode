class Solution {
public:
int compress(vector<char>& chars) 
{
        int i = 0; 
        int ansIndex = 0; 
        int n = chars.size();
	
      while(i<n)
      {
            int j = i + 1;  // camparing next element with j. 
       
            while( j < n && chars[i] == chars[j])
            {
                j++;
            }
        
        //we will reach here 
        // when we have triverse the whole vector 
        // or we have encountered any new/Different characters
        
        //Storing Oldchar here. 
            chars[ansIndex++] = chars[i];
            int count = j - i;
        
            if(count > 1)
            {
            // Converting count into single digit and saving that into answer.
                string cnt = to_string(count);
           
                for ( char ch : cnt )
                {
                    chars[ansIndex++] = ch; 
                }
            }
            
          i = j; // Moving to new/different character.
        }
        return ansIndex;

    }
};