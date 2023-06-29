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
        if(n % 2 != 0)
        {
            for(int i = 0; i < n; i++) cout << 1 << ' ';
        }
        else
        {
            for(int i = 0; i < n - 2; i++) cout << 2 << ' ';
            cout << 1 << ' ' << 3;
        }
        cout << endl;
    }
    return 0;
}