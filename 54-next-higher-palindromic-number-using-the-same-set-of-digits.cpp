//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string str) 
    { 
        string ans = "";
        vector<int> vec;
        int l = 0, r = str.size() - 1;
        
        while(l < r)
        {
            vec.push_back(str[l] - '0');
            l++;
            r--;
        }
        
        int n = vec.size();
        if(n > 1)
        {
            int i = 1;
            int lastInc = -1;
            while(i < n)
            {
                if(vec[i] > vec[i - 1])
                {
                    lastInc = i;
                }
                i++;
            }
            
            if(lastInc == -1)
                return "-1";
            
            int val = vec[lastInc];//5
            int index = lastInc;//1
            for(i = lastInc; i < n; ++i)
            {
                if(vec[i] > vec[lastInc - 1] && vec[i] < vec[index])
                index = i;
            }
            int temp = vec[index];
            vec[index] = vec[lastInc - 1];
            vec[lastInc - 1] = temp;
            sort(vec.begin() + lastInc, vec.end());
        }
        else
            return "-1";
        for(int i = 0; i < n; ++i)
        {
            ans += to_string(vec[i]);
        }
        if(l == r)
            ans += str[l];
        for(int i = (n - 1); i >= 0; --i)
        {
            ans += to_string(vec[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends