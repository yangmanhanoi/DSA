#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
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
    faster() int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = max(a[1] * a[2], a[n - 1] * a[n]);
    ans = max(max(ans, a[1] * a[2] * a[n]), a[n - 2] * a[n - 1] * a[n]);
    cout << ans << endl;
    return 0;
}