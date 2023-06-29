#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
        int a, b, c; cin >> a >> b >> c;
        double d = (double)-c/a;
        double e = (double) b/a;
        double delta = (double)pow(d, 2)/4 + pow(e,3) /27;
        double ans = (double)cbrt(-d/2 + sqrt(delta)) + cbrt(-d/2 - sqrt(delta));
        cout << setprecision(4) << fixed << ans << endl;
    }
}