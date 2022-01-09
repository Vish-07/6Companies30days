#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution{
    public:
    string colName (ll n)
    {
        string ans = "";
        while(n)
        {
            ll rem = n % 26;
            
            string str = "A";
            if(rem == 0)
            {
                str[0] = 'Z';
                n = (n / 26 - 1);
            }
            else
            {
                str[0] = 'A' + rem - 1;
                n /= 26;
            }
            ans = str + ans;
            
        }
        return ans;
    }
};
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}