using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,i,sum;
        cin>>n>>sum;
        long long a[n+1];
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long begin=1,end=1;
        int val=0;
        i=1;
        while(i<=n && val!=sum)
        {
            val=val+a[i];
            end=i;
            while(val>sum)
            {
                val=val-a[begin];
                begin++;
            }
            i++;
        }
        if(val==sum)
        {
            cout<<begin<<" "<<end<<'\n';
        }
        else
        {
            cout<<"-1"<<'\n';
        }
        
    }

	return 0;
}