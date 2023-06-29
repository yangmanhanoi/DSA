#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        int n; cin >> n;
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int check = 0;
        deque<ll> dq;
        for(int i = 0; i < n; i++)
        {
            if(!dq.empty() and a[i] < dq.back())
            {
                check = 1;
                break;
            }
            else dq.push_back(a[i]);
        }
        if(check) cout << dq.size()<< endl;
        else cout << 0 << endl;
    }
    return 0;
}