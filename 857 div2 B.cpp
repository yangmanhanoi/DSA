#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
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
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int cnt = 0, sum = 0, rem = 0;
        for (int i = 1; i <= n; i++)
        {
            while (a[i] != 2)
            {
                i++;
                cnt++;
            }
            if (a[i] == 2)
            {
                if (cnt >= 4)
                {
                    sum += (cnt / 4) * 3;
                    rem += (cnt / 4) * 2;
                    if (rem % 4 == 0) rem -= (rem / 4);  
                }
            }
            else
            {
                sum += cnt;
                rem += cnt;
            }
            cnt = 0;
        }
        cout << sum << endl;
    }
    return 0;
}