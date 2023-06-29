#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
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
        vi a(n);
        unordered_map<int,int> mp;
        int cnt = 0;
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            if(mp[a[i]] == 0) cnt++;
            mp[a[i]]++;
        }
        if(cnt == 1)
        {
            cout << "NO\n";
            continue;
        }
        sort(a.begin(), a.end(), greater<int>());
        cout << "YES\n";
        stack<int> st;
        for(auto &i : s)
        {
            st.push(i);
        }
        while(!st.empty())
        {
            cout << st.top() << ' ';
            mp[st.top()]--;
            st.pop();
        }
        for(int i = 0; i < n; i++)
        {
            while(mp[a[i]] >= 1)
            {
                cout << a[i] << ' ';
                mp[a[i]]--;
            }
        }
        cout << endl;
    }
    return 0;
}