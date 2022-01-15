// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int target){
        int steps = 0;
        int sum = 0;
        while(sum < target)
        {
            sum += steps;
            steps++;
        }
        
        while((sum - target) % 2 == 1)
        {
            sum += steps;
            steps++;
        }
        return steps - 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends