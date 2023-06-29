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
        int f[1000005] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        int ans = 0, res;
        for(int i = 0; i < n; i++)
        {
            if(f[a[i]] > ans)
            {
                ans = f[a[i]];
                res = a[i];
            }
        }
        if(ans <= n/2) cout << "NO";
        else cout << res;
        cout << endl;
    }
    return 0;
}