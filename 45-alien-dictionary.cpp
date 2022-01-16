// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void DFSRec(unordered_set<int> adj[], int u, string &ans, vector<bool> &visited)
    {
        visited[u] = true;
        for(auto v: adj[u])
        {
            if(visited[v] == false)
            {
                DFSRec(adj, v, ans, visited);
            }
        }
        ans.push_back(u+'a');
    }
    
    string topologicalSort(unordered_set<int> adj[], int V)
    {
        string ans;
        vector<bool> visited(V, false);
        
        for(int v=0; v < V; v++)
        {
            if(adj[v].size())
            {
                for(auto u: adj[v])
                {
                    if(visited[u] == false)
                    {
                        DFSRec(adj, u, ans, visited);
                    }
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string findOrder(string words[], int N, int K) 
    {
        unordered_set<int> adj[K];
        for(int i = 0; i < N-1; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            
            for(int j = 0; j < min(word1.size(), word2.size()); j++)
            {
                if(word1[j] != word2[j])
                {
                    int index1 = word1[j] - 'a';
                    int index2 = word2[j] - 'a';
                    
                    adj[index1].insert(index2);
                    
                    break;
                }
            }
        }
        return topologicalSort(adj,K);
 
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends