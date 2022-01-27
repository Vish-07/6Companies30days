class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int i = 1;
        int alice = 0, bob = 0;
        while(colors[i] != '\0')
        {
            int count = 1;
            while(colors[i] != '\0' && colors[i] == colors[i - 1])
            {
                i++;
                count++;
            }    
            if(colors[i - 1] == 'A')
                alice += (count >= 3 ? count - 2 : 0);
            else
                bob += (count >= 3 ? count - 2 : 0);
            
            if(colors[i] != '\0')
                i++;
        }
        return alice > bob;
    }
};