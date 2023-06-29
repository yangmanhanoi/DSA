#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        int n, m; cin >> n >> m;
        int a[n + 5][m + 5];
        int res[n + 5][m + 5] = {};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < m; i++) res[0][i] = a[0][i];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j]) res[i][j] = res[i - 1][j] + 1;
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            stack<int> st;
            int x[m], y[m];
            for(int j = 0; j < m; j++)
            {
                while(!st.empty() and res[i][st.top()] >= res[i][j]) st.pop();
                if(st.empty()) x[j] = 0;
                else x[j] = st.top() + 1;
                st.push(j);
            }
            st = {};
            st.push(m -1);
            y[m - 1] = m - 1;
            for(int j = m - 2; j >= 0; j--)
            {
                while(!st.empty() and res[i][st.top()] >= res[i][j]) st.pop();
                if(st.empty()) y[j] = m - 1;
                else y[j] = st.top() - 1;
                st.push(j);
            }
            for(int j = 0; j < m; j++)
            {
            //	cout << "(" << x[j] << ' ' << y[j] << ")";
                ans = max(ans, (y[j] - x[j] + 1) * res[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}