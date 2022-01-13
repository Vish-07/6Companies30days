#include<iostream>
#include<vector>
using namespace std;

 // } Driver Code Ends
class Solution
{
    void helper(vector<vector<int>>& grid, int i, int j, int& count, int& rows, int& cols)
    {
        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0 || grid[i][j] == 2)
            return;
        count++;
        grid[i][j] = 2;
        helper(grid, i + 1, j, count, rows, cols);
        helper(grid, i - 1, j, count, rows, cols);
        helper(grid, i, j + 1, count, rows, cols);
        helper(grid, i, j - 1, count, rows, cols);
        helper(grid, i + 1, j + 1, count, rows, cols);
        helper(grid, i + 1, j - 1, count, rows, cols);
        helper(grid, i - 1, j + 1, count, rows, cols);
        helper(grid, i - 1, j - 1, count, rows, cols);
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int count = 0;
                    helper(grid, i, j, count, rows, cols);
                    ans = max(ans, count);
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends