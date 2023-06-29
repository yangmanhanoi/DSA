#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int a[n + 5];
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int x = 0;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] < a[i - 1])
            {
                int tmp = (a[i - 1] + a[i]) / 2;
                if((a[i - 1] + a[i]) % 2 != 0) tmp++;
                x = max(x, tmp);
            }
        }
        int check = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] > a[i - 1])
            {
                if((a[i - 1] + a[i]) / 2 < x)
                {
                    check = 0;
                    break;
                }
            }
        }
        if(!check) cout << -1 << endl;
        else cout << x << endl;
    }
    return 0;
}