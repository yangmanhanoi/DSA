#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int n;
int a[15][15];
vector<string> vs;
string s = "";
void dfs(int i, int j)
{
    for(int k = 0; k < 2; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 and i1 < n and j1 >= 0 and j1 < n and a[i1][j1])
        {
            if(i1 > i) s += "D";
            else s += "R";
            if(i1 == n - 1 and j1 == n - 1)
            {
                vs.push_back(s);
            //    a[i][j] = 0;
                s.pop_back();
                return;
            }       
            dfs(i1, j1);
//            a[i1][j1] = 0;
            s.pop_back();
        }
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) cin >> a[i][j];
        }
        if(a[0][0] == 0) cout << -1 << endl;
        else
        {
            dfs(0, 0);
            if(vs.size() == 0) cout << -1 << endl;
            else
            {
                for(auto &i : vs) cout << i << ' ';
                cout << endl;
            }
        }
        vs.clear();
        s = "";
    }
    return 0;
}