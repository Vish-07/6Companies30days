#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        int i = 0;
        
        if(s[0] >= 'a' && s[0] <= 'z')
        {
            s[0] = s[0] - 'a' + 'A';
        }
        
        while(s[i] != '\0')
        {
            string part = "";
            part += (s[i] - 'A' + 'a');
            i++;
            while(s[i] >= 'a' && s[i] <= 'z')
            {
                part += s[i];
                i++;
            }
            ans += part;
            if(s[i] != '\0')
                ans += " ";
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends