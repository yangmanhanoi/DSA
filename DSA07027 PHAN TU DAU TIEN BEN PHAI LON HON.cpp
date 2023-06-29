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
        int n; cin >> n;
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        stack<int> st;
        vector<int> vs;
        st.push(a[n]);
        for(int i = n - 1; i >= 1; i--)
        {
            while(!st.empty() and a[i] >= st.top())
            {
                st.pop();
            }
            if(!st.empty()) vs.push_back(st.top());
            else vs.push_back(-1);
            st.push(a[i]);
        }
        for(int i = vs.size() - 1; i >= 0; i--) cout << vs[i] << ' ';
        cout << -1 << endl;
    }
    return 0;
}