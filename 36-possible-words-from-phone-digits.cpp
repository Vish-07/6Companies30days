//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> sol;
    vector<string> record = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(int a[], int n, int index, string s)
    {
        if(index == n)
        {
            sol.push_back(s);
            return;
        }
        for(int i = 0; i < record[a[index] - 2].size(); ++i)
        {
            s += record[a[index] - 2][i];
            helper(a, n, index + 1, s);
            s.pop_back();
        }
        return;
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        string s = "";
        helper(a, N, 0, s);
        return sol;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends