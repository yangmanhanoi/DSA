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
    faster()
    int k = 1;
    test()
    {
        int n, m;
        cin >> n >> m;
        int a[n + 5][m + 5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        int tmp = 0;
        int res1, res2;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += a[i][j];
            }
            if (sum > tmp)
            {
                tmp = sum;
                res1 = i;
            }
        }
       // cout << res1 << endl;
        tmp = 0;
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if(j != res1) sum += a[j][i];
            }
            if (sum > tmp)
            {
                tmp = sum;
                res2 = i;
            }
        }
      // cout << res2 << endl;
        cout << "Test " << k++ << ":\n" ; 
        for (int i = 0; i < n; i++)
        {
            if (i == res1)
                    continue;
            for (int j = 0; j < m; j++)
            {
                if (j != res2)
                    cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}