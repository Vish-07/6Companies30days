class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& a) 
    {
        vector<int> res;
        sort(a.begin(), a.end());

        while (a.size() > 1) {
            int num = a[a.size() - 1] - a[a.size() - 2];
            unordered_map<int, int> m;
            for (int i : a)
                m[i]++;

            vector<int> exc, inc;
            for (int i : a) {
                if (m[i] > 0) {
                    exc.push_back(i);
                    inc.push_back(i + num);
                    m[i]--;
                    m[i + num]--;
                }
            }

            if (find(exc.begin(), exc.end(), 0) != exc.end()) {
                a = exc;
                res.push_back(num);
            } else {
                a = inc;
                res.push_back(-1 * num);
            }
        }
        return res;
 
        
    }
};