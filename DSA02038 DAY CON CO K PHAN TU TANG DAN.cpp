#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
int a[20];
vector<int> res;
vector<string> vs;
void Try(int i)
{
    if(res.size() == k)
    {
        string s= "";
        for(auto &i : res)
        {
            s += to_string(i) + ' ';
        }
        vs.push_back(s);
    }
    for(int j = i; j <= n; j++)
    {
        res.push_back(a[j]);
        Try(j + 1);
        res.pop_back();
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        sort(vs.begin(), vs.end());
        Try(1);
        for(auto &i : vs) cout << i << endl;
        res.clear();
        vs.clear();
    }  
    return 0;
}