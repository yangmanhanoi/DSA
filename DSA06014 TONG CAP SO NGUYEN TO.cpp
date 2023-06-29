#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int f[1000005] = {};
int main()
{
    for(int i = 1; i <= 1000000; i++) f[i] = 1;
    f[1] = 0;
    for(int i = 2; i <= 1000; i++)
    {
        if(f[i])
        {
            for(int j = i*i; j <= 1000000; j += i) f[j] = 0;
        }
    }
    faster();
    test()
    {
        int n; cin >> n;
        int check = 0;
        for(int i = 2; i <= n; i++)
        {
            if(f[i] and f[n - i])
            {
                check = 1;
                cout << i << ' ' << n - i << endl;
                break;
            }
        }
        if(check == 0) cout << -1 << endl;
    }
    return 0;
}