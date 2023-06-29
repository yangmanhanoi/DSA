#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int MOD = 1e6 + 7;
struct Matrix
{
    ll a[2][2];
    Matrix operator*(Matrix B)
    {
        Matrix A = *this;
        Matrix D;
        memset(D.a, 0, sizeof(D.a));
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int z = 0; z < 2; z++)
                {
                    D.a[i][j] += (A.a[i][z]*B.a[z][j]) % MOD;
                    D.a[i][j] %= MOD;
                }
            }
        }
        return D;
    }
};
Matrix binPow(Matrix A, ll k)
{
    if(k == 1) return A;
    Matrix tmp = binPow(A, k/2);
    tmp = tmp*tmp;
    if(k % 2 == 1) return tmp*A;
    else return tmp;
}
int main()
{
    faster()
    Matrix A;
    A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;
    A.a[1][1] = 0;
    ll f[15];
    f[0] = f[1] = f[2] = 1;
    for(int i = 3; i <= 10; i++) f[i] = f[i - 1] + f[i - 2];
    test()
    {
        ll n; cin >> n;
        if(n <= 10) cout << f[n] << endl;
        else
        {
            Matrix res = binPow(A, n - 1);
            ll ans = res.a[0][0];
            ans %= MOD;
            cout << ans << endl;
        }
        
    }
    return 0;
}