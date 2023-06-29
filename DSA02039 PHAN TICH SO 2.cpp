#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
vector<int> vs;
vector<vector<int>> res;
void Try(int i, int sum = 0)
{
    if(sum > n) return;
    if(sum == n)
    {
        int check = 1;
        for(int x = 0; x < vs.size() - 1; x++)
        {
            if(vs[x] < vs[x + 1])
            {
                check = 0;
                break;
            }
        }
        if(check)
        {
            res.push_back(vs);
        }
        return;
    }
    for(int j = n; j >= 1; j--)
    {
        vs.push_back(j);
        Try(j, sum + j);
        vs.pop_back();
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        Try(1);
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i].size() == 1)
            {
                cout << "(" << res[i][0] << ") "; 
            }
            else
            {
                cout << "(" << res[i][0] << ' ';
                for(int j = 1; j < res[i].size() - 1; j++) cout << res[i][j] << ' ';
                cout << res[i][res[i].size() - 1] << ") ";
            }
        }
        cout << endl;
        res.clear();
        vs.clear();
    }
    return 0;
}