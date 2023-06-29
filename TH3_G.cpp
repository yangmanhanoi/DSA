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
        int x[n + 5];
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and a[st.top()] <= a[i]) st.pop();
            if(st.empty()) x[i] = 0;
            else x[i] = st.top() + 1;
            st.push(i);
        }
        for(int i = 0; i < n; i++)
        {
            cout << i - x[i] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}