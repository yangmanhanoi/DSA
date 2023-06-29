#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
        test()
    {
        int n, k;
        cin >> n >> k;
        vi v(n);
        F(i, 0, n)
        {
            cin >> v[i];
        }
        if (is_sorted(v.begin(), v.end()))
            cout << 0 << endl;
        else
        {
            int idx = 1;
            F(i, 0, n)
            {
                if(v[i] == idx) idx++;
            }
           // cout << idx << endl;
            int ans = (n - idx + 1) / k;
            if((n - idx + 1) % k != 0) ans++;
            cout << ans << endl;
        }
    }
    return 0;
}