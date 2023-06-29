#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int ans = -1;
int n = 8;
int a[10][10];
int column[10] = {}, diagonal1[40] = {}, diagonal2[40] = {};
void Try(int i, int sum = 0)
{
    if (i == 9)
    {
        ans = max(ans, sum);
        return;
    }
    for (int j = 1; j <= 8; j++)
    {
        if (column[j] == 0 and diagonal1[i - j + n] == 0 and diagonal2[i + j - 1] == 0)
        {
            column[j] = diagonal1[i - j + n] = diagonal2[i + j - 1] = 1;
            Try(i + 1, sum + a[i][j]);
            column[j] = diagonal1[i - j + n] = diagonal2[i + j - 1] = 0;
        }
    }
}
int main()
{
    faster()
        test()
    {
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cin >> a[i][j];
            }
        }
        Try(1);
        cout << ans << endl;
        memset(column, 0, sizeof(column));
        memset(diagonal1, 0, sizeof(diagonal1));
        memset(diagonal2, 0, sizeof(diagonal2));
        ans = -1;
    }
    return 0;
}