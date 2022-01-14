#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string decToBinary(int n)
{
    string ans = "";
    while(n)
    {
        int p = (n % 2);
        ans += to_string(p);
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<string> generate(int N)
{
	vector<string> ans;
	
	for(int i = 1; i <= N; ++i)
	{
	    string curr = decToBinary(i);
	    ans.push_back(curr);
	}
	
	return ans;
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
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends