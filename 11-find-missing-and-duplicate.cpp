#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *A, int n) 
    {
        int xor_ = 0;
        for(int i = 0; i < n; ++i)
        {
            xor_ ^= A[i];
        }
    
        for(int i = 1; i <= n; ++i)
        {
            xor_ ^= i;
        }
    
        int rsb = xor_ & -xor_;
    
        int x = 0;
        int y = 0;
    
        for(int i = 0; i < n; ++i)
        {
            int val = A[i];
            if((val & rsb) == 0)
                x ^= val;
            else
                y ^= val;
        }
    
        for(int i = 1; i <= n; ++i)
        {
            if((i & rsb) == 0)
                x ^= i;
            else
                y ^= i;
        }
        int *ans = new int[2];
        for(int i = 0; i < n; ++i)
        {
            int val = A[i];
            if(val == x)
            {
                ans[0] = x;
                ans[1] = y;
                return ans;
            }
            else if(val == y)
            {
                ans[0] = y;
                ans[1] = x;
                return ans;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}