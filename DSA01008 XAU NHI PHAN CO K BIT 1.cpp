#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k, ok = 1;
string s = "";
void ktao()
{
    for(int i = 0; i < n; i++) s += '0';
}
void sinh()
{
    int i = n - 1;
    while(i >= 0 and s[i] == '1') --i;
    if(i == -1) ok = 0;
    else
    {
        s[i] = '1';
        for(int j = i + 1; j < n; j++) s[j] = '0';
    }
}
int check()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1') cnt++;
    }
    if(cnt == k) return 1;
    else return 0;
}
int main()
{
    faster();
    test()
    {
        cin >> n >> k;
        ktao();
        while (ok)
        {
            if(check()) cout << s << endl;
            sinh();
        }
        ok = 1;
        s = "";
    }
    return 0;
}