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
struct data
{
    string s;
    int sumDigits;
    int idx;
};
// Tham khảo: https://tutorialspoint.dev/algorithm/sorting-algorithms/find-largest-multiple-3-array-digits-set-2-time-o1-space
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
        int sum = 0;
        priority_queue<int> q;
        priority_queue<int, vector<int>, greater<>> q1, q2;
        for (int i = 1; i <= n; i++)
        {
            q.push(a[i]);
            sum += a[i];
            if (a[i] % 3 == 1)
                q1.push(a[i]);
            else if (a[i] % 3 == 2)
                q2.push(a[i]);
        }
        if ((sum % 3 == 1 and q1.size() == 0 and q2.size() < 2) or (sum % 3 == 2 and q2.size() == 0 and q1.size() < 2))
            cout << -1;
        else
        {
            int x1 = -1, x2 = -1;
            string res = "";
            if (sum % 3 == 1)
            {
                if (q1.empty())
                {
                    x1 = q2.top();
                    q2.pop();
                    x2 = q2.top();
                }
                else
                    x1 = q1.top();
            }
            else if (sum % 3 == 2)
            {
                if (q2.empty())
                {
                    x1 = q1.top();
                    q1.pop();
                    x2 = q1.top();
                }
                else
                    x1 = q2.top();
            }
            while (!q.empty())
            {
                int top = q.top();
                q.pop();
                if (top != x1 and top != x2)
                    res += top + '0';
                else if (top == x1)
                    x1 = -1;
                else if (top == x2)
                    x2 = -1;
            }
            if (res.empty())
                cout << -1;
            else
            {
                int i = 0;
                while (res[i] == '0')
                {
                    ++i;
                }
                if (i == res.size() - 1)
                    cout << -1;
                else
                    cout << res.substr(i);
            }
            cout << endl;
        }
    }
    return 0;
}