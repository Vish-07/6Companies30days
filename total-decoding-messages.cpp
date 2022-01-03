#include<bits/stdc++.h>
using namespace std;

class Solution {
    int MOD = 1000000007;
	public:
	    int helper(string& str, int i, vector<long>& dp)
	    {
	        if(dp[i] != -1)
	            return dp[i];
	            
	        if(str[i] == '\0')
	            return 1;
	       
	        long ans = 0;
	        if(str[i] != '0')
	            ans = helper(str, i + 1, dp);
	            
	        ans %= MOD;
	        
	        if(str[i] == '1' && str[i + 1] != '\0')
	            ans += (helper(str, i + 2, dp));
            if(str[i] == '2' && str[i + 1] >= '0' && str[i + 1] <= '6')
                ans += (helper(str, i + 2, dp));
                
            ans %= MOD;
            dp[i] = ans;    
	        return ans;
	    }
	
		int CountWays(string str)
		{
	        int n = str.size();
	        vector<long> dp(n + 1, -1);
	        return helper(str, 0, dp);
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
} 