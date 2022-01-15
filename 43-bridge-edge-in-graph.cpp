#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> visited1(V, 0), visited2(V, 0);
        queue<int> q;
        q.push(c);
        visited1[c] = 1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                if((curr == c && adj[curr][i] == d) || (curr == d && adj[curr][i] == c))
                    continue;
                if(visited1[adj[curr][i]] == 0)
                    q.push(adj[curr][i]);
                visited1[adj[curr][i]] = 1;
            }
        }
        q.push(d);
        visited2[d] = 1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                if((curr == c && adj[curr][i] == d) || (curr == d && adj[curr][i] == c))
                    continue;
                if(visited2[adj[curr][i]] == 0)
                    q.push(adj[curr][i]);
                visited2[adj[curr][i]] = 1;
            }
        }
        for(int i = 0; i < V; ++i)
        {
            if(visited1[i] ^ visited2[i] == 1)
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends