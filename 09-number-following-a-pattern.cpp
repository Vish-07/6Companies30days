#include <iostream>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string s)
    {
        string ans;
        int n = s.size();
        int k = 0, max = 1;
        while(s[k] == 'D')
        {
            max++;
            k++;
        }
        ans += (max + '0');
        // cout << ans << endl;
        int val = max;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'I')
            {
                int j = i + 1;
                while(s[j] == 'D')
                {
                    j++;
                    max++;
                }
                max++;
                ans += (max + '0');
                val = max;
            }
            else
            {
                val--;
                ans += (val + '0');
            }
        }
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 