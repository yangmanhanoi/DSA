#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k, cnt = 0, x = 0, check = 0;
int a[25];
void Try(int cnt = 0, int sum = 0)
{
    if(sum > x) return;
    if(check) return;
    if(cnt == k)
    {
        check = 1;
        return;
    }
    for(int j = 1; j <= n; j++)
    {
        if(sum == x) Try(cnt + 1);
        else Try(cnt, sum + a[j]);
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            x += a[i];
        }
     //   sort(a + 1, a + n + 1);
        if(x % k != 0) cout << 0;
        else
        {
            x /= k;
            Try(1);
            if(check) cout << 1;
            else cout << 0;
        }
        cout << endl;
        cnt = 0;
        x = 0;
        check = 0;
    }
    return 0;
}