#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int price[], int n)
{
   vector <int> span(n, 0);
   stack<int> st;
   st.push(0);
   span[0] = 1;
   
   for(int i = 1; i < n; ++i)
   {
        while(!st.empty() && price[st.top()] <= price[i])
        {
           st.pop();
        }
        span[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
   }
   
   return span;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends