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
    for(int i = 3; i <= 92; i++) f[i] = f[i - 1] + f[i - 2];
}
int main()
{
    faster()
    f[1] = f[2] = 1;
    sinh();
    test()
    {
        ll n, k; cin >> n >> k;
        while(n > 2)
        {
            if(k <= f[n - 2]) n -= 2;
            else
            {
                n--;
                k -= f[n - 1];
            }
        }
        if(n == 1) cout << 0 << endl;
        else if(n == 2) cout << 1 << endl;
    }
    return 0;
}