#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
vector<string> v;
vector<string> vs;
vector<vector<string>> ans;
void backTrack(int i)
{
    if (vs.size() == k)
    {
        for(auto i: vs) cout << i << ' ';
        cout << endl;
        return;
    }
    for (int j = i; j < v.size(); j++)
    {
        vs.push_back(v[j]);
        backTrack(j + 1);
        vs.pop_back();
    }
}
int main()
{
    faster()
    cin >> n >> k;
    v.clear();
    ans.clear();
    vector<string> a(n + 1);
    set<string> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    for(auto i : s) v.push_back(i);
    backTrack(0);
    return 0;
    // int n; cin >> n;
    // int a[n + 5];
    // int f[1005] = {};
    // vector<int> v;
    // for(int i = 1; i <= n; i++)
    // {
    //     cin >> a[i];
    //     if(a[i] % 2 != 0)
    //     {
    //         f[i] = 1;
    //         v.push_back(a[i]);
    //     }
    // }
    // sort(v.begin(), v.end(), greater<int>());
    // int idx = 0;
    // for(int i = 1; i <= n; i++)
    // {
    //     if(f[i] == 1)
    //     {
    //         cout << v[idx] << ' ';
    //         idx++;
    //     }
    //     else cout << a[i] << ' ';
    // }
    // return 0;
}