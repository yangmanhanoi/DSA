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
string start = "", finish = "1238004765";
// Xoay nua phai theo chieu thuan
int l1[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
// xoay nua trai theo chieu thuan
int r1[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
// Xoay nua phai theo chieu nguoc
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
// xoay nua trai theo chieu nguoc
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};
#define ll long long
string rotate(string &s, int a[])
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        res += s[a[i]];
    }
    return res;
}
int bfs()
{
    int ans = 1e9;
    queue<pair<string, int>> q1, q2;
    q1.push({start, 0});
    q2.push({finish, 0});
    unordered_map<string, int> m;
    while (!q1.empty())
    {
        pair<string, int> top = q1.front();
        q1.pop();
        string tmp = rotate(top.first, l1);
        if (!m[tmp])
        {
            m[tmp] = top.second + 1;
            q1.push({tmp, m[tmp]});
        }
        if (m[tmp] == 15)
            break;
        tmp = rotate(top.first, r1);
        if (!m[tmp])
        {
            m[tmp] = top.second + 1;
            q1.push({tmp, m[tmp]});
        }
        if (m[tmp] == 15)
            break;
    }
    while (!q2.empty())
    {
        pair<string, int> top = q2.front();
        q2.pop();
        if (m[top.first] > 0)
            ans = min(ans, top.second + m[top.first]);
        string tmp = rotate(top.first, l2);
        q2.push({tmp, top.second + 1});
        if (top.second == 15)
            break;
        tmp = rotate(top.first, r2);
        q2.push({tmp, top.second + 1});
        if (top.second == 15)
            break;
    }
    return ans;
}
int main()
{
    faster()
        test()
    {
        int x;
        for (int i = 0; i < 10; i++)
        {
            cin >> x;
            start += to_string(x);
        }
        cout << bfs() << endl;
        start = "";
    }
    return 0;
}