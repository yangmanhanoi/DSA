#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        int n, m, k; cin >> n >> m >> k;
        int a[n + 5], b[m + 5], c[k + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int j = 1; j <= m; j++) cin >> b[j];
        for(int i = 1; i <= k; i++) cin >> c[i];
        int i1,i2,i3;
        i1 = i2 = i3 = 1;
        int cnt = 0;
        while(i1 <= n and i2 <= m and i3 <= k)
        {
            if(a[i1] == b[i2] and b[i2] == c[i3] and a[i1] == c[i3])
            {
                cnt++;
                cout << a[i1] << ' ';
                i1++; i2++; i3++;
            }
            else if(a[i1] < b[i2]) i1++;
            else if(b[i2] < c[i3]) i2++;
            else i3++;
        }
        if(cnt == 0) cout << "NO\n";
        else cout << "\n";
    }
    return 0;
}