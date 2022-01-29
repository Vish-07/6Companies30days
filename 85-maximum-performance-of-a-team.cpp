class Solution {
public:
    struct employee{
        int speed;
        int efficiency;
    };
    
    static bool compare(employee e1, employee e2)
    {
        return e1.efficiency > e2.efficiency;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        employee record[n];
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0, speedSum = 0;
        
        for(int i = 0; i < n; ++i)
        {
            record[i].speed = speed[i];
            record[i].efficiency = efficiency[i];
        }
        sort(record, record + n, compare);
        
        for(int i = 0; i < n; ++i)
        {
            if(pq.size() > (k - 1))
            {
                speedSum -= pq.top();
                pq.pop();
            }
            pq.push(record[i].speed);
            speedSum += record[i].speed;
            ans = max(ans, speedSum * record[i].efficiency);
        }
        return (ans % 1000000007);
    }
};