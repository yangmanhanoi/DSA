#include <bits/stdc++.h>
using namespace std;
int n, k, a[20], sum[20], ans = 0;
void Try(int i, int cnt = 0)
{
    if (i > n and cnt == k)
    {
        ans++;
        return;
    }
    for (int j = i; j <= n; j++)
    {
        if (sum[j] - sum[i] + a[i] == sum[n] / k)
        {
            Try(j + 1, cnt + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sum[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[n] % k != 0)
        cout << "0";
    else
    {
        Try(1);
        cout << ans;
    }
    cout << endl;
    ans = 0;
    return 0;
}