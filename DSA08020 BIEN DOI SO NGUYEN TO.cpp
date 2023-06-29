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

int main()
{
    faster()
    int f[10005] = {};
    f[0] = f[1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        if (f[i] == 0)
        {
            for (int j = i * i; j <= 10000; j += i)
                f[j] = 1;
        }
    }
    test()
    {
        string s, t;
        cin >> s >> t;
        if(s == t)
        {
            cout << 0 << endl;
            continue;
        }
        if (s > t)
            swap(s, t);
        //  cout << s << ' ' << t << endl;
        queue<string> q;
        q.push(s);
        unordered_map<string, int> m;
        int visited[10005] = {};
        int check = 1;
        while (check)
        {
            string top = q.front();
            int y = stoi(top);
            //  if(top == t) break;
            q.pop();
            for (int i = top.size() - 1; i >= 0; i--)
            {
                string res = top;
                if (res[i] != t[i])
                {
                    for (int j = 9; j >= 0; j--)
                    {
                        if (i == 0 and j == 0)
                            continue;
                        res[i] = j + '0';
                        int x = stoi(res);
                        if (f[x] == 0 and x != y and !visited[x])
                        {
                            q.push(res);
                            m[res] = m[top] + 1;
                            visited[x] = 1;
                            if (res == t)
                            {
                                check = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << m[t] << endl;
    }
    return 0;
}