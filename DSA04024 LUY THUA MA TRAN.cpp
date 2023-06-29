#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        int n; cin >>n;
        int a[n + 5];
        for(int i = 1; i <= n;i++) cin >> a[i];
        int b[n + 5];
        stack<int> st;
        for(int i = 1; i <= n; i++) b[i] = 1;
        st.push(1);
        for(int i = 2; i <= n; i++)
        {
            while(!st.empty() and a[i] >= a[st.top()])
            {
                b[i] += b[st.top()];
                st.pop();
            }
            if(st.empty() or a[i] < a[st.top()]) st.push(i);
        }
        for(int i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << endl;
    }
    return 0;
}