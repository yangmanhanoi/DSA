#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
int a[1000005];
bool check0()
{
    for(int i = 2; i <= n; i++) if(a[i] % 2) return 0;
    return 1;
}
bool check1()
{
    for(int i = 2; i <= n; i++) if(a[i] % 2 == 0) return 0;
    return 1;
}
int main()
{
    faster()
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if((a[1] % 2 == 0 and check0()) or (a[1] % 2 == 1 and check1())) cout << "yes\n";
    else cout << "no\n";
    return 0;
}