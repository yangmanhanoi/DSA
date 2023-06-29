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
        int n; cin >> n;
        vector<int> vs(n), res(n);
        for(int i = 0; i < n; i++)
        {
            cin >> vs[i];
            res[i] = vs[i];
        }
        sort(res.begin(),res.end());
        int l = 0, r = n - 1;
        while(vs[l] == res[l]) ++l;
        while(vs[r] == res[r]) --r;
        cout << l + 1 << ' ' << r + 1 << endl;
    }
    return 0;
}