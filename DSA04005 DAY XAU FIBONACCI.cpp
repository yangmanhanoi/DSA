#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll f[93];
void sinh()
{
    for(int i = 3; i <= 92; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}
char binSearch(ll n, ll k)
{
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k == 1)
    {
        if(n % 2 == 0) return 'B';
        else return 'A';
    }
    if(n - 2 > 0)
    {
        if(k <= f[n - 2]) binSearch(n - 2, k);
        else binSearch(n - 1, k - f[n - 2]);
    }
}
int main()
{
    faster()
    f[1] = f[2] = 1;
    sinh();
    test()
    {
        ll n, k;
        cin >> n >> k;
        while(n > 2)
        {
            if(k <= f[n - 2]) n -= 2;
            else
            {
                k -= f[n - 2];
                --n;
            }
        }
        if(n == 1) cout << 'A';
        else if(n == 2) cout << 'B';
        cout << endl;
    }
    return 0;
}