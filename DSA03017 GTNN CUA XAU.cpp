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
        int n; cin >> n;
        string s; cin >> s;
        int f[30] = {};
        for(char i : s)
        {
            f[i - 'A']++;
        }
        priority_queue<int> q;
        for(auto i : f) q.push(i);
        while(n--)
        {
            int top = q.top();
            q.pop();
            top--;
            q.push(top);
        }
        int sum = 0;
        while(!q.empty())
        {
            sum += (q.top()*q.top());
            q.pop();
        }
        cout << sum << endl;
    }
    return 0;
}