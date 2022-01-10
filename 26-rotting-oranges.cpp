class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int oranges = 0, rot = 0, ans = 0;
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> bfs;
        
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(grid[i][j] != 0)
                    oranges++;
                if(grid[i][j] == 2)
                    bfs.push({i, j});
            }
        }
        
        if(oranges == 0)
            return 0;
        
        while(!bfs.empty())
        {
            int current = bfs.size();
            rot += current;
            
            if(rot == oranges)
                return ans;
            
            while(current--)
            {
                int curr_x = bfs.front().first;
                int curr_y = bfs.front().second;
                bfs.pop();
                for(auto i: direction)
                {
                    int x = curr_x + i.first;
                    int y = curr_y + i.second;
                    
                    if(x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0 || grid[x][y] == 2)
                        continue;
                    else
                    {
                        grid[x][y] = 2;
                        bfs.push({x, y});
                    }
                }
            }
            ans++;
        }
        
        return -1;
        
        
    }
};