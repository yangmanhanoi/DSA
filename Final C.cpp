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
    int n; cin >> n;
    int a[n + 5][5];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    ll dp[n + 5][8];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1 << n); j++) dp[i][j] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= 4; j *= 2)
        {
            int bitmask = 0;
            for(int v = 1; v <= 3; v++)
            {
                
            }
        }
    }
}