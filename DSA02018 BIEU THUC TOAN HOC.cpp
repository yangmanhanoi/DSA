#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<int> v(5);
char c[3] = {'+', '-', '*'};
int a[5];
vector<vector<int>> vs, per;
void T
int main()
{
    faster()
    for(int i = 0; i < 5; i++) v[i] = i;
    while (next_permutation(v.begin(), v.end()))
    {
        per.push_back(v);
    }
    test()
    {
        for(int i = 0; i < 5; i++) cin >> a[i];
    }
}