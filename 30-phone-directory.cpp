// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        vector<string> v;
        set<string> directory;
        
        for(int i = 0; i < n; i++)
            directory.insert(contact[i]);
        
        
        for(auto i=directory.begin();i!=directory.end();i++)
        {
            if((*i)[0] == s[0])
                v.push_back(*i);
        }
        if(v.empty())
            v.push_back("0");  
            
        ans.push_back(v);
        
        for(int i = 1; i < s.length(); i++)
        {
            vector<string> curr;
            for(int j = 0; j < ans.back().size(); j++)
            {
                if(ans.back()[j][i] == s[i])
                    curr.push_back(ans.back()[j]);
            }
            if(curr.empty())
                curr.push_back("0");
            ans.push_back(curr);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends