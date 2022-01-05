#include <bits/stdc++.h>
using namespace std;

class Solution{
    string decodedString(string& s, int& i)
    {
        string result;
        while(i < s.size() && s[i] != ']')
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int k = 0;
                while(i < s.size() && (s[i] >= '0' && s[i] <= '9'))
                {
                    k = (k * 10) + (s[i++] - '0');
                }
                i++;
                string str = decodedString(s, i);
                while(k--)
                {
                    result += str;
                }
                i++;
            }
            else
            {
                result += s[i++];
            }
        }
        return result;
    }

    string decodeStringUsingStack(string s) 
    {
        stack<int> frequency;
        stack<string> substr;
        int num = 0;
        int i = 0;
        string current = "";
        while(s[i] != '\0')
        {
            if(s[i] == '[')
            {
                substr.push(current);
                frequency.push(num);
                current = "";
                num = 0;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == ']')
            {
                string temp = current;
                int freq = frequency.top();
                frequency.pop();
                current = substr.top();
                substr.pop();
                while(freq--)
                {
                    current += temp;
                }
                num = 0;
            }
            else
            {
                current += s[i];
            }
            i++;
        }
        return current;
    }
public:
    string decodedString(string s){
        int i = 0;
        return decodedString(s, i);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}