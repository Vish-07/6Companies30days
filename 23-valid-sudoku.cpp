class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        int n = mat.size();
        
        for(int i = 0; i < n; ++i)
        {
            vector<bool> vec(10, false);
            for(int j = 0; j < n; ++j)
            {
                if(mat[i][j] != '.')
                {
                    if(vec[mat[i][j] - '0'])
                        return 0;
                    vec[mat[i][j] - '0'] = true;
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
        {
            vector<bool> vec(10, false);
            for(int j = 0; j < n; ++j)
            {
                if(mat[j][i] != '.')
                {
                    if(vec[mat[j][i] - '0'])
                        return 0;
                    vec[mat[j][i] - '0'] = true;
                }
            }
        }
        // cout << "here\n";
        for(int i = 0; i < n; i += 3)
        {
            for(int j = 0; j < n; j += 3)
            {
                vector<bool> vec(10, false);
                for(int k = i; k < (3 + i); ++k)
                {
                    for(int x = j; x < (3 + j); ++x)
                    {
                        if(mat[k][x] != '.')
                        {
                            if(vec[mat[k][x] - '0'])
                                return 0;
                            vec[mat[k][x] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};