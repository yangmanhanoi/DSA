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
        int a[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(next_permutation(a + 1, a + n + 1))
        {
            for(int i = 1;i <= n; i++) cout << a[i] << ' ';
        }
        else
        {
            for(int i = 1; i <= n; i++) cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}