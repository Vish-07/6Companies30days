#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        if(word[index] == '\0')
        {
            return true;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }
        else
        {
            char temp = board[i][j];
            board[i][j] = ' ';
            bool ans = helper(board, word, i + 1, j, index + 1) ||
            helper(board, word, i - 1, j, index + 1) ||
            helper(board, word, i, j + 1, index + 1) ||
            helper(board, word, i, j - 1, index + 1);
            
            board[i][j] = temp;
            return ans;
        }
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(helper(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends