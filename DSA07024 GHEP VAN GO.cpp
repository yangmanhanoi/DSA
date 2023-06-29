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
        for(int i = 0; i < n; i++) cin >> a[i];
        stack<int> st;
        int l[n + 5], r[n + 5];
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and a[st.top()] >= a[i]) st.pop();
            if(st.empty()) l[i] = 0;
            else l[i] = st.top() + 1;
            st.push(i);
        }
        // for(int i = 0; i < n; i++)
        // {
        //     cout << l[i] << ' ';
        // }
        cout << endl;
        st = {};
        st.push(n - 1);
        r[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--)
        {
            while(!st.empty() and a[st.top()] >= a[i]) st.pop();
            if(st.empty()) r[i] = n - 1;
            else r[i] = st.top() - 1;
            st.push(i);
        }
        int length, height;
        int x = 0;
        ll ans = -1;
        // for(int i = 0; i < n; i++)
        // {
        //     cout << r[i] << ' ';
        // }
        for(int i = 0; i < n; i++)
        {
        	int tmp = r[i] - l[i] + 1;
        	if(tmp >= a[i])
        	{
        		if(1ll * a[i] * a[i] > ans)
        		{
        			ans = 1ll * a[i] * a[i];
        			x = a[i];
        		}
        	}
        }
        cout << x << endl;
    }
    return 0;
}