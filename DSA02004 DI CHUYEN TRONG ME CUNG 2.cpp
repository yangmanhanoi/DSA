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
int a[15][15];
int n;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string str = "DLRU";
string s = "";
vector<string> vs;
void Try(int i, int j)
{
    // if(a[0][0] == 0) return;
    if (i == n - 1 and j == n - 1)
    {
        vs.push_back(s);
      //  a[i][j] = 1;
      //  s.pop_back();
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 0 and i1 < n and j1 >= 0 and j1 < n and a[i1][j1])
        {
            s += str[k];
            a[i1][j1] = 0;
            Try(i1, j1);
            a[i1][j1] = 1;
            s.pop_back();
        }
    }
}
int main()
{
    faster()
        test()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        if (a[0][0] == 0 or a[n - 1][n - 1] == 0)
            cout << -1 << endl;
        else
        {
            a[0][0] = 0;
            Try(0, 0);
            if (vs.size() == 0)
                cout << -1;
            else
            {
                for (auto &i : vs)
                    cout << i << ' ';
            }
            cout << endl;
        }
        vs.clear();
        s = "";
    }
    return 0;
}