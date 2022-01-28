class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& ocean)
    {
        if(i < 0 || j < 0 || i >= ocean.size() || j >= ocean[0].size())
            return;
        
        if(heights[i][j] < prev || ocean[i][j])
            return;
        
        ocean[i][j] = true;
        dfs(heights, i + 1, j, heights[i][j], ocean);
        dfs(heights, i - 1, j, heights[i][j], ocean);
        dfs(heights, i, j + 1, heights[i][j], ocean);
        dfs(heights, i, j - 1, heights[i][j], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>> res;
        if(heights.size() == 0 || heights[0].size() == 0)
            return res;
        
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        
        for(int i = 0; i < col; ++i)
        {
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, row - 1, i, INT_MIN, atlantic);
        }    
        
        for(int i = 0; i < row; ++i)
        {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, col - 1, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    vector<int> ans(2);
                    ans[0] = i;
                    ans[1] = j;
                    res.push_back(ans);
                }    
            }
        }
        return res;
    }
};