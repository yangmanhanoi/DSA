#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        vector<pair<int,int>> vs;
        for(int i = 0; i < n; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            vs.push_back({y, w});
        }
        sort(vs.begin(), vs.end(), cmp);
        int cnt = 0, sum = 0;
        int f[1005] = {};
        for(auto &i : vs)
        {
            for(int j = i.first; j >= 1; j--)
            {
                if(!f[j])
                {
                    cnt++;
                    f[j] = 1;
                    sum += i.second;
                    break;
                }
            }
        }
        cout << cnt << ' ' << sum << endl;
    }
    return 0;
}