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
        test()
    {
        int n;
        cin >> n;
        string s1 = "", s2 = "";
        int par, child;
        string c;
        int check = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> par >> child >> c;
            s1 += to_string(par) + ' ' + to_string(child) + ' ' + c + ' ';
        }
       // cout << s1 << endl;
        int m;
        cin >> m;
        if (n != m)
            check = 0;
        else
        {
            for (int i = 0; i < m; i++)
            {
                cin >> par >> child >> c;
                s2 = to_string(par) + ' ' + to_string(child) + ' ' + c + ' ';
                //cout << s2 << endl;
                if (s1.find(s2) == string::npos)
                {
                    check = 0;
                    break;
                }
            }
        }

        if (check)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}