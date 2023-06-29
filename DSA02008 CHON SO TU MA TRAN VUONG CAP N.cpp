#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[105][105];
int main()
{
    int n, m; cin >> n >> m;
    int a[n + 5][n + 5];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<string> vs;
    int b[n];
    for(int i = 1; i <= n; i++) b[i] = i;
    do
    {
        ll sum = 0;
        string str = "";
        for(int i = 1; i <= n; i++)
        {
            sum += a[i][b[i]];
            str += to_string(b[i]) + " ";
        }
        if(sum == m) vs.push_back(str);
    } while (next_permutation(b + 1, b + n  + 1));
    cout << vs.size() << endl;
    for(auto &i : vs)
    {
        cout << i << endl;
    }
    return 0;
}