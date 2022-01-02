#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string str)
{     
    string ans;
    int i = 0;
    int count = 0;
    while(i < str.size())
    {
        count = 0;
        char curr = str[i];
        while(str[i] == curr)
        {
            count++;
            i++;
        }
        ans += curr;
        ans += (count + '0');
    }
    return ans;
}     
 
