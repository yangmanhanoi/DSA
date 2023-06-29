#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int degIn[1005] = {}, degOut[1005] = {};
int n, m;
bool check()
{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(degIn[i] != degOut[i]) return 0;
    }
    return 1;
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        memset(degIn, 0, sizeof(degIn));
        memset(degOut, 0, sizeof(degOut));
        while(m--)
        {
            int x, y; cin >> x >> y;
            degIn[y]++;
            degOut[x]++;
        }
        cout << check() << endl;
    }
    return 0;
}