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
        int n; cin >> n;
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        int left[n + 5], right[n + 5];
        left[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] > a[i - 1]) left[i] = left[i - 1];
            else left[i] = i;
        }
        right[n] = n;
        for(int i = n - 1; i >= 1; i--)
        {
            if(a[i] > a[i + 1]) right[i] = right[i + 1];
            else right[i] = i;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, right[i] - left[i] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}