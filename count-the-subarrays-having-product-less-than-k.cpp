#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        long long int product=1,j=0,ans=0;
        for(int i=0;i<n;i++)
        {
            product*=a[i];
            while(j<n && product >= k)
            {
                product/=a[j++];
            }
            ans+=(i-j+1);
        }
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}