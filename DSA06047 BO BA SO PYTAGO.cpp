#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster();
    test()
    {
        int n; cin >> n;
        ll a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i]*a[i];
        }
        sort(a, a + n);
        int check = 0;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(binary_search(a + j + 1, a + n, a[i] + a[j]))
                {
                    check = 1;
                    break;
                }
            }
        }
        if(!check) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}