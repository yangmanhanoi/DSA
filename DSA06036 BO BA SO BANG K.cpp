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
        int n, k; cin >> n >> k;
        int a[n + 5];
        int check = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                if(a[l] + a[r] > k - a[i]) --r;
                else if(a[l] + a[r] < k - a[i]) ++l;
                else{
                    check = 1;
                    break;
                }
            }
            if(check) break;
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}