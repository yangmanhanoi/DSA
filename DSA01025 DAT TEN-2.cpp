#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
vector<char> v, res;
void print()
{
    for(int i = 0; i < k; i++) cout << res[i];
    cout << endl;
}
void Try(int i)
{
    if(res.size() == k)
    {
        print();
        return;
    }
    for(int j = i; j < n; j++)
    {
        res.push_back(v[j]);
        Try(j + 1);
        res.pop_back();
    }
}
int main()
{
    
    for(int i = 65; i <= 90; i++) v.push_back(char(i));
    faster()
    test()
    {
        cin >> n >> k;
        Try(0);
    }
    return 0;
}