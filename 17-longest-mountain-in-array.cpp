#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, count = 0;
        int n = arr.size(), i = 1;
        
        while(i < n)
        {
            int flag = 0;
            while(i < n && arr[i] > arr[i - 1])
            {
                count++;
                flag = 1;
                i++;
            }
            if(flag == 1)
            {
                while(i < n && arr[i] < arr[i - 1])
                {
                    count++;
                    flag = 2;
                    i++;
                }
            }
            if(flag == 2)
            {
                count += 1;
                ans = max(ans, count);
                count = 0;
            }
            else
            {
                i++;
                count = 0;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    Solution ob;
    cout << ob.longestMountain(arr) << endl;
}