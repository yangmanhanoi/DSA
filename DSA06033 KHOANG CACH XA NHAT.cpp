#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> right(n + 1, -1e9);
        for(int i = n - 1; i >= 0; i--)
        {
            right[i] = max(right[i + 1], v[i]);
        }
        int res = -1e9;
        for(int i = 0; i < v.size(); i++)
        {
            int l = i + 1, r = n - 1, ans = i;
            while(l <= r)
            {
                int mid = (l + r)/2;
                if(v[i] < right[mid])
                {
                    ans = max(ans, mid);
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            if(ans == i) res = max(res, -1);
            else res = max(res, ans - i);
        }
        cout << res << endl;
    }
    return 0;
}