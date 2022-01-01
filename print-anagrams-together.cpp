#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) 
    {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> hash;
        for(int i = 0; i < string_list.size(); ++i)
        {
            string current = string_list[i];
            sort(current.begin(), current.end());
            hash[current].push_back(string_list[i]);
        }
        
        for(auto it = hash.begin(); it != hash.end(); it++)
        {
            answer.push_back(it->second);
        }
        return answer;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}