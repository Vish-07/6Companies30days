#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> mp;
        int max = 0;
        string ans;
        vector<string> sol(2);
        for(int i = 0; i < n; ++i)
        {
            mp[arr[i]]++;
            if(mp[arr[i]] > max)
            {
                max = mp[arr[i]];
                ans = arr[i];
            }
            else if(mp[arr[i]] == max)
            {
                if(arr[i] < ans)
                    ans = arr[i];
            }
        }
        sol[0] = ans;
        sol[1] = to_string(max);
        return sol;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends