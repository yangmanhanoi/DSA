#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() ll t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    // test()
    // {
    //     ll A, B; cin >> A >> B;
    //     string a = to_string(A);
    //     string b = to_string(B);
    //     ll l = b.size();
    //     for(ll i = 0; i < b.size(); i++)
    //     {
    //         if(b[i] != '9')
    //         {
    //             l--;
    //             break;
    //         }
    //     }
    //     ll ans = A*l;
    //     cout << ans << endl;
    // }
    vector<int> vs;
    int x;
    while(cin >> x)
    {
        vs.push_back(x);
    }
    for(auto &i : vs) cout << i << endl;
    return 0;
}