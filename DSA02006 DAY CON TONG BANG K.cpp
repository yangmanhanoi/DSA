#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
int a[15];
vector<int> vs;
int check = 0;
void print()
{
    cout << "[";
    for(int i = 0; i < vs.size() - 1; i++) cout << vs[i] << ' ';
    cout << vs[vs.size() - 1] << "] ";
}
void Try(int i, int sum = 0)
{
    if(sum > k) return;
    if(sum == k)
    {
        print();
        check++;
        return;
    }
    for(int j = i + 1; j <= n; j++)
    {
        vs.push_back(a[j]);
        Try(j, sum + a[j]);
        vs.pop_back();
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
        Try(0);
        if(check == 0) cout << -1;
        vs = {};
        check = 0;
        cout << endl;
    }
    return 0;
}