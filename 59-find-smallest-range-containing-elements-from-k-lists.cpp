#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    struct Compare{
        bool operator()(int* v1,int* v2)
        {
            return v1[0] > v2[0];
        }
    };
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<int*, vector<int*>, Compare> pq;
        pair<int, int> ans = {0, 100000};
        int upper = 0;
         
        for(int i = 0; i < k; ++i)
        {
            int* curr = new int[3];
            curr[0] = KSortedArray[i][0];
            curr[1] = i;
            curr[2] = 0;
            pq.push(curr);
            if(KSortedArray[i][0] > upper)
                upper = KSortedArray[i][0];
        }
        
        ans = {pq.top()[0], upper};
        //cout << ans.first << " " << ans.second << endl;
        while(1)
        {
            int* curr = pq.top();
            pq.pop();
            if(curr[2] == (n - 1))
                break;
            int* vec = new int[3];
            vec[0] = KSortedArray[curr[1]][curr[2] + 1];
            vec[1] = curr[1];
            vec[2] = curr[2] + 1;
            pq.push(vec);
            if(KSortedArray[curr[1]][curr[2] + 1] > upper)
            {   
                upper = KSortedArray[curr[1]][curr[2] + 1];
            }
            if(upper - pq.top()[0] < ans.second - ans.first)
                ans = {pq.top()[0], upper};
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends