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
    return a.second < b.second;
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        vector<pair<int,int>> vs;
        while(n--)
        {
            int x, y;
            cin >> x >> y;
            vs.push_back({x, y});
        }
        sort(vs.begin(), vs.end(), cmp);
        int cnt = 0, cur = -1;
        for(auto i : vs)
        {
            if(i.first >= cur)
            {
                cnt++;
                cur = i.second;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}