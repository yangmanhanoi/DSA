#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
        int n, x; cin >> n >> x;
        vector<int> vs(n);
        for(int i = 0; i < n; i++) cin >> vs[i];
        if(binary_search(vs.begin(),vs.end(), x)) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}