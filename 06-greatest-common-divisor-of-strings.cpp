#include <iostream>
using namespace std;

class Solution {
public:
    int gcd(int num1, int num2)
    {
        if(num2 == 0)
            return num1;
        return gcd(num2, num1 % num2);
    }    
        
    string gcdOfStrings(string str1, string str2) 
    {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.length(), str2.length())): "";   
    }
};

int main()
{
    string str1, str2;
    Solution ob;
    cin >> str1 >> str2;
    cout << ob.gcdOfStrings(str1, str2);
}