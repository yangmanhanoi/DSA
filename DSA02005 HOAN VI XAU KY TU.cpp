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
        string s; cin >> s;
        do
        {
            /* code */
            cout << s << ' ';
        } while (next_permutation(s.begin(), s.end()));
        cout << endl;
    }
    return 0;
}