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
        cin.ignore();
        string s; cin >> s;
        int posL = -1, posR = 1e9;
        s = "*" + s;
        //cout << s << endl;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == 'L') posL = max(posL, i);
            else posR = min(posR, i);
        }
        //cout << posL << ' ' << posR << endl;
        if(posL == -1) cout << -1 << endl;
        else if(posR == 1e9) cout << -1 << endl;
        else if(posL > posR) cout << 0 << endl;
        else cout << posL << endl;
    }
    return 0;
}