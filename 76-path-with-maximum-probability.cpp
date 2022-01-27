class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        // Creating a weighted graph
        vector<vector<pair<int, double>>> adj(n);
        
        for(int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> prob(n, (double)0.0);
        priority_queue<pair<double, int>> pq; // Max heap for probability at every point
        pq.push({1.0, start});
        
        prob[start] = 1.0;
        
        while(!pq.empty())
        {
            int temp = pq.top().second;
            pq.pop();
            
            for(auto v : adj[temp])
            {
                if(prob[temp] * v.second > prob[v.first])
                {
                    prob[v.first] = prob[temp] * v.second;
                    pq.push({prob[v.first], v.first});
                }
            }
        }
        return prob[end];
    }
};