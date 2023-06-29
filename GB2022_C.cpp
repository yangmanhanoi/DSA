#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool checkPrime(ll n)
{
    if(n == 1 or n == 0) return 0;
    else if(n == 2 or n == 3) return 1;
    else if(n % 2 == 0 or n % 3 == 0) return 0;
    ll sqr = sqrt(n);
    for(ll i = 5; i <= sqr; i += 6)
    {
        if(n % i == 0 or n % (i + 2) == 0) return 0;
    }
    return 1;
}
int main()
{
    faster()
    test()
    {
        ll n; cin >> n;
        vll a(n);
        int check = 1;
        F(i, 0, n) cin >> a[i];
        F(i, 0, n)
        {
            F(j, i + 1, n)
            {
                if(a[i] == a[j])
                {
                    check = 0;
                    break;
                }
            }
        }
        if(!check)
        {
            cout << "no\n";
            continue;
        }
        for(int i = 2; i <= n; i++)
        {
            if(checkPrime(i))
            {
                vi cnt(i);
                for(auto &x : a) cnt[x % i]++;
                if(*min_element(cnt.begin(), cnt.end()) >= 2)
                {
                    check = 0;
                    break;  
                }
            }
        }
        if(!check) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}