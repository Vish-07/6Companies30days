#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

string find_recent(string s1, string s2)
{
    vector<int> tokens1, tokens2;
    stringstream check1(s1), check2(s2);

    string intermediate;

    while(getline(check1, intermediate, '.'))
    {
        tokens1.push_back(stoi(intermediate));
    }
    while(getline(check2, intermediate, '.'))
    {
        tokens2.push_back(stoi(intermediate));
    }
    int i = 0, j = 0;
    while (i < tokens1.size() && j < tokens2.size())
    {
        if(tokens1[i] > tokens2[j])
            return s1;
        else if(tokens2[j] > tokens1[i])
            return s2;
        i++;
        j++;
    }
    if(i < tokens1.size())
        return s1;
    return s2;
}

int main() {
	string version1, version2;
	getline(cin, version1);
	getline(cin, version2);
	cout << find_recent(version1, version2) << endl;
	return 0;
}
