#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        int n, k; cin >> n >> k;
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int sum[n + 5];
        sum[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        int tmp1 = abs(sum[n] - 2*sum[k]);
        int tmp2 = abs(sum[n] - sum[n - k]*2);
        cout << max(tmp1, tmp2) << endl;
    }
    return 0;
}