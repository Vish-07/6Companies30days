class Solution {
public:
    void helper(queue<int>& bfsHelper, vector<int>& ans, vector<int>& degree, vector<vector<int>>& adj)
    {
        while(!bfsHelper.empty())
        {
            int curr = bfsHelper.front();
            bfsHelper.pop();
            ans.push_back(curr);
            //cout << curr << endl;
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                degree[adj[curr][i]]--;
                if(degree[adj[curr][i]] == 0)
                    bfsHelper.push(adj[curr][i]);
            }
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> inDegree(numCourses, 0);
        queue<int> bfsHelper;
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i = 0; i < numCourses; ++i)
        {
            for(int j = 0; j < adj[i].size(); ++j)
            {
                inDegree[adj[i][j]]++;
            }
        }
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(inDegree[i] == 0)
            {
                bfsHelper.push(i);
                //cout << "Here";
            }    
        }
        
        if(bfsHelper.size() == 0)
            return ans;
        
        helper(bfsHelper, ans, inDegree, adj);
        vector<int> empty;
        for(int i = 0; i < numCourses; ++i)
        {
            if(inDegree[i] != 0)
                return empty;
        }
        
        return ans;
        
        
    }
};