//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends


//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
void helper(vector<string> &res, string s, int open, int close, int n)
{
    if(s.size() == 2*n)
    {
        res.push_back(s);
        return ;
    }
    
    if(open < n)
    {
        helper(res, s+'(', open + 1, close, n);
    }
    
    if(close < open)
    {
        helper(res, s + ')', open, close + 1, n);
    }
}

vector<string> AllParenthesis(int n) 
{
    vector<string> res;
    helper(res, "", 0, 0, n);
    return res;
}

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> result = AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends