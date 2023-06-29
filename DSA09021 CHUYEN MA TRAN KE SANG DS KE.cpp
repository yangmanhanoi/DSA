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
    int a[n + 5][n + 5];
    vector<int> Ke[n + 5];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
            {
                Ke[i].push_back(j);
              //  Ke[j].push_back(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(auto &x : Ke[i]) cout << x << ' ';
        cout << endl;
    }
    return 0;
}