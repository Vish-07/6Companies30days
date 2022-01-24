#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    string max;
    public:
    void swap(string& str, int& i, int& j)
    {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    
    void helperMax(string str, int& n, int k, int index)
    {
        if(k == 0)
            return;
            
        char maxchar = str[index];
        
        for(int j = index + 1; j < n; ++j)
        {
            if(maxchar < str[j])
                maxchar = str[j];
        }
        
        if(maxchar != str[index])
            k--;
            
        for(int i = (n - 1); i >= index; --i)
        {
            if(str[i] == maxchar)
            {
                swap(str, i, index);
                
                if(str > max)
                    max = str;
                helperMax(str, n, k, index + 1);
                
                swap(str, i, index);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       max = str;
       int n = str.size();
       helperMax(str, n, k, 0);
       return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends