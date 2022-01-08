#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    queue<char> q;
		    int hash[26] = {0};
		    int i = 0;
		    string ans = A;
		    while(A[i] != '\0')
		    {
		        hash[A[i] - 'a']++;
		        q.push(A[i]);
		        while(!q.empty() && hash[q.front() - 'a'] > 1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		            ans[i] = '#';
		        else
		            ans[i] = q.front();
		        i++;
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends