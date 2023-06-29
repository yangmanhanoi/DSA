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
int cnt = 1e9;
int n;
string vs[15];
int f[35][35] = {}, x[15];
int visited[15] = {};
int fx[200];
int count(string a, string b)
{
    int sum = 0;
    memset(fx, 0, sizeof(fx));
    for (int i = 0; i < a.size(); i++)
        fx[a[i]]++;
    for (int i = 0; i < b.size(); i++)
        fx[b[i]]++;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (fx[i] > 1)
            sum++;
    }
    return sum;
}
void Update()
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        count += f[x[i - 1]][x[i]];
    }
    cnt = min(cnt, count);
}
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            x[i] = j;
            visited[j] = 1;
            if (i == n)
            {
                Update();
            }
            Try(i + 1);
            visited[j] = 0;
        }
    }
}
int main()
{
    faster()
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> vs[i];
        visited[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            f[i][j] += count(vs[i], vs[j]);
            f[j][i] = f[i][j];
        }
    }
    Try(1);
    cout << cnt << endl;
    return 0;
}