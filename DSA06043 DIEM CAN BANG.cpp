#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        int n; cin >> n;
        int a[n];
        for(int i = 1; i <= n; i++) cin >> a[i];
        int sum[n];
        sum[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        int ans = -1;
        for(int i = 2; i <= n - 1; i++)
        {
            if(sum[i] - a[i] == sum[n] - sum[i])
            {
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}