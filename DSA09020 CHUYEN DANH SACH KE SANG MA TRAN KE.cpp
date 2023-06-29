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
    memset(a, 0, sizeof(a));
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        string s; getline(cin, s);
        stringstream ss(s);
        while(ss >> s)
        {
            int x = stoi(s);
            a[i][x] = a[x][i] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}