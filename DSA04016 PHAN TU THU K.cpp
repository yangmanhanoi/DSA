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
        int m, n, k; cin >> m >> n >> k;
        int a[m + 5], b[n + 5];
        for(int i = 1; i <= m; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        int idx1, idx2;
        idx1 = idx2 = 1;
        int c[n + m + 5];
        int idx = 1;
        while(idx1 <= m and idx2 <= n)
        {
            if(a[idx1] > b[idx2])
            {
                c[idx++] = b[idx2];
                idx2++;
            }
            else if(a[idx1] < b[idx2])
            {
                c[idx++] = a[idx1];
                idx1++;
            }
            else
            {
                c[idx++] = a[idx1];
                c[idx++] = b[idx2];
                idx1++; idx2++;
            }
        }
        cout << c[k] << endl; 
    }
    return 0;
}