#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, ans = 1e9;
int a[20][20], used[20] = {};
vector<int> vs;
void Try(int i, int sum = 0)
{
    if(sum > ans) return;
    if(vs.size() == n)
    {
        // tmp += a[vs.back()][1];
         ans = min(ans, sum + a[vs.back()][1]);
           // cout << ans << ' ';
       // for(auto &x : vs) cout << x << ' ';
        cout << endl;
        return;
    }
    for(int j = 2; j <= n; j++)
    {
        if(!used[j])
        {
            used[j] = 1;
            vs.push_back(j);
            Try(i + 1, sum + a[vs[vs.size() - 2]][j]);
            used[j] = 0;
            vs.pop_back();
        }
    }
}
int main()
{
    faster()
    cin >> n;
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vs.push_back(1);
    Try(1);
    cout << ans << endl;
    return 0;
}