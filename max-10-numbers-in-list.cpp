#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue <int, vector<int>, greater<int> > pq;
    int x;
    for(int i = 0; i < 10; ++i)
    {
        cin >> x;
        pq.push(x);
    }
    for(int i = 10; i < 10000000; ++i)
    {
        cin >> x;
        if(x > pq.top())
        {
            pq.pop();
            pq.push(x);
        }
    }
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
