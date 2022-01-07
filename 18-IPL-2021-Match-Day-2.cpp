#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int i = 0, j = 0;
        
        while(j < k)
        {
            pq.push({arr[j], j});
            j++;
        }
        ans.push_back(pq.top().first);
        if(pq.top().second == 0)
            pq.pop();
        i = 1;  
        while(j < n)
        {
            pq.push({arr[j], j});
            while(!pq.empty() && pq.top().second < i)
                pq.pop();
                
            ans.push_back(pq.top().first);
            i++;
            j++;
        }
        return ans;
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} 