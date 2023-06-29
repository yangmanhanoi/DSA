#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll findMax(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '5') s[i] = '6';
    }
    ll ans = stoll(s);
    return ans;
}
ll findMin(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '6') s[i] = '5';
    }
    ll ans = stoll(s);
    return ans;
}
int main()
{
    string a, b;
    cin >> a >> b;
    ll minA = findMin(a), minB = findMin(b);
    ll maxA = findMax(a), maxB = findMax(b);
    cout << minA + minB << ' ' << maxA + maxB << endl;
    return 0;
}