#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, x;
int a[25];
vector<int> vs;
vector<vector<int>> ans;
void Try(int i, int sum = 0)
{
    if(sum > x) return ;
    if(sum == x)
    {
        ans.push_back(vs);
        return;
    }
    for(int j = i; j <= n; j++)
    {
        vs.push_back(a[j]);
        Try(j, sum + a[j]);
        vs.pop_back();
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> x;
        for(int i = 1; i <= n; i++) cin >> a[i];
        Try(1);
        if(ans.size() > 0)
        {
            cout << ans.size() << ' ';
            for(int i = 0; i < ans.size(); i++)
            {
                if(ans[i].size() != 1)
                {
                    cout << "{" << ans[i][0] << ' ';
                    for(int j = 1; j < ans[i].size() - 1; j++)
                    {
                        cout << ans[i][j] << ' ';
                    }
                    cout << ans[i][ans[i].size() - 1] << "} ";
                }
                else cout << "{" << ans[i][0] << "} ";
            }
        }
        else cout << -1;
        cout << endl;
        vs.clear();
        ans.clear();
    }
    return 0;
}