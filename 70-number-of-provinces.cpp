class Solution {
public:
    void dfs(vector<bool>& visited, vector<vector<int>>& isConnected, int i, int& n)
    {
        if(visited[i])
            return;
        
        visited[i] = true;
        
        for(int j = 0; j < n; ++j)
        {
            if(isConnected[i][j] == 1)
            {
                dfs(visited, isConnected, j, n);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                count++;
                dfs(visited, isConnected, i, n);
            }
        }
        
        return count;
    }
};