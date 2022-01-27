//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int NumberOfPath( int, int);

// Position this line where user code will be pasted

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        
        //calling NumberOfPath() function
        cout << NumberOfPath(a,b) << endl;
    }
}

// } Driver Code Ends


//User function template in C++

int NumberOfPath(int a, int b) 
{
    int mat[a][b];
    for(int i = 0; i < a; ++i)
    {
        mat[i][0] = 1;
    }
    for(int i = 0; i < b; ++i)
    {
        mat[0][i] = 1;
    }
    for(int i = 1; i < a; ++i)
    {
        for(int j = 1; j < b; ++j)
        {
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
        }
    }
    return mat[a - 1][b - 1];
}
