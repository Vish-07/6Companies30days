#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCycle(vector<vector<int>>& graph, vector<int>& state, int curr)
    {
        if(state[curr] == 2) //processing
            return true;
        
        state[curr] = 2;
        for(int i = 0; i < graph[curr].size(); ++i)
        {
            if(state[graph[curr][i]] != 1)
            {
                if(isCycle(graph, state, graph[curr][i]))
                {
                    return true;
                }
            }
        }
        
        state[curr] = 1; //processed;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prereq) 
	{
	    vector<vector<int>> graph(N);
	    vector<int> state(N, 0);
	    
	    for(int i = 0; i < prereq.size(); ++i)
	    {
	        graph[prereq[i].first].push_back(prereq[i].second);
	    }
	    
	    for(int i = 0; i < N; ++i)
	    {
	        if(state[i] == 0)
	        {
	            if(isCycle(graph, state, i))
	                return false;
	        }
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends