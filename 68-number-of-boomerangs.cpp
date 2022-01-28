class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int ans = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            unordered_map<int, int> mp;
            for(int j = 0; j < points.size(); ++j)
            {
                if(i == j)
                    continue;
                int dist = pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2);
                mp[dist]++;
            }
            for(auto i : mp)
            {
                ans += (i.second * (i.second - 1));
            }
        }
        return ans;
    }
};