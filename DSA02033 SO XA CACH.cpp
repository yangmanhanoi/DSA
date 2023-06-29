#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool check(string s)
{
    for(int i = 0; i < s.size() - 1; i++)
    {
        int tmp1 = s[i] - '0', tmp2 = s[i + 1] - '0';
        if(abs(tmp1 - tmp2) == 1) return 0;
    }
    return 1;
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        string s = "";
        for(int i = 1; i <= n; i++) s += (i + '0');
        do
        {
            /* code */
            if(check(s))
            {
                cout << s << endl;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << endl;
    }
    return 0;
}