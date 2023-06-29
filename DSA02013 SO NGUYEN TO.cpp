#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int posP, posS;
int n, p, s;
vector<int> vs, res;
vector<vector<int>> ans;
void Try(int i, int sum = 0)
{
    if(sum > s) return;
    if(sum == s and res.size() == n)
    {
        ans.push_back(res);
        return;
    }
    for(int j = i; j <= posS; j++)
    {
        res.push_back(vs[j]);
        Try(j + 1, sum + vs[j]);
        res.pop_back();
    }
}
int main()
{
    faster()
    int f[1005] = {};
    f[0] = f[1] = 1;
    for(int i = 2; i <= 1000; i++)
    {
        if(f[i] == 0)
        {
            for(int j = i*i; j <= 1000; j += i)
            {
                f[j] = 1;
            }
        }
    }
    for(int i = 2; i <= 1000; i++) if(f[i] == 0) vs.push_back(i);
    test()
    {
        cin >> n >> p >> s;
        posP = upper_bound(vs.begin(),vs.end(), p) - vs.begin();
        posS = lower_bound(vs.begin(), vs.end(), s) - vs.begin();
        Try(posP);
        cout << ans.size() << endl;
        for(auto &i : ans)
        {
            for(int j = 0; j < i.size(); j++)
            {
                cout << i[j] << ' ';
            }
            cout << endl;
        }
        res.clear();
        ans.clear();
    }
    return 0;
}