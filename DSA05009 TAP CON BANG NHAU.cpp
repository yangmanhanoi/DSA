#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[105];
int res = 0;
int cnt = 0;
int n;
void Try(int i, int sum = 0)
{
    if(sum > res/2) return;
    if(sum == res/2)
    {
        cnt++;
        return;
    }
    for(int j = i; j <=n; j++)
    {
        if(cnt > 0) return;
        Try(j + 1, sum + a[j]);
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            res += a[i];
        }
        if(res % 2 != 0) cout << "NO\n";
        else
        {
            Try(1);
            if(cnt == 0) cout << "NO\n";
            else cout << "YES\n";
        }
        cnt = 0;
        res = 0;
    }
    return 0;
}