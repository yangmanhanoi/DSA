#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool checkPrime(int x)
{
    if(x == 0 or x == 1) return 0;
    int n = sqrt(x);
    for(int i = 2; i <= n; i++)
    {
        if(x % i == 0) return 0;
    }
    return 1;
}
int n, a[20];
vector<vector<int>> res;
vector<int> vs;
void Try(int i, int sum = 0)
{
    if(vs.size() > 0 and checkPrime(sum))
    {
        res.push_back(vs);
    }
    for(int j = i; j <= n; j++)
    {
        vs.push_back(a[j]);
        Try(j + 1, sum + a[j]);
        vs.pop_back();
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(1);
        sort(res.begin(), res.end());
        for(auto &i : res)
        {
            for(auto &j : i)
            {
                cout << j << ' ';
            }
            cout << endl;
        }
        res.clear();
        vs.clear();
    }
    return 0;
}