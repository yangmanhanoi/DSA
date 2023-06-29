#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
        int a[n + 5], b[n + 5];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int check = 1;
        for(int i = 0; i < n; i++)
        {
            if(b[i] != a[i] and b[i] != a[n - i - 1])
            {
                check = 0;
                break;
            }
        }
        if(check) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}