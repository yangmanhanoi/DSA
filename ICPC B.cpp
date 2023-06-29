#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
int main()
{
    faster()
    string s; cin >> s;
    unordered_map<int, int> mp;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(mp[s[i] - '0'] == 0) cnt++;
        mp[s[i] - '0'] = 1;
    }
 //   cout << cnt << endl;
    if(cnt == 10) cout << "Impossible" << endl;
    else
    {
        int resMin = 50, resMax = -1;
        for(int i = 0; i <= 9;i++)
        {
            if(mp[i] == 0)
            {
                resMax = max(resMax, i);
                resMin = min(resMin, i);
            }
        }
        int findLow = -1,findUp = -1;
        string str = s.substr(0,2);
        if(mp[1] == 0 and mp[0] == 0) findUp = 10;
        else
        {
            for(int i = s[0] - '0'; i <= 9; i++)
            {
                if(mp[i] == 0)
                {
                    findUp = i;
                    break;
                }
            }
        }
        if(s[0] - '0' == 1 and mp[0] == 1) findLow = 0;
        else
        {
            for(int i = s[0] - '0'; i >= 0; i--)
            {
                if(mp[i] == 0)
                {
                    findLow = i;
                    break;
                }
            }
        }
        
        string tmp1 = "", tmp2 = "";
        ll ans;
        if(findUp == -1)
        {
            tmp1 += findLow + '0';
            for(int i = 1; i < s.size(); i++)
            {
                tmp1 += resMax + '0';
            }
            cout << stoll(tmp1);
        }
        else if(findLow == -1)
        {
            tmp2 += to_string(findUp);
            for(int i = 1; i < s.size(); i++)
            {
                tmp2 += resMin + '0';
            }
            cout << stoll(tmp2);
        }
        else
        {
            tmp1 += findLow + '0';
            tmp2 += to_string(findUp);
            for(int i = 1; i < s.size(); i++)
            {
                tmp1 += resMax + '0';
                tmp2 += resMin + '0';
            }
//            cout << tmp1 << ' ' << tmp2;
            ll x = stoll(tmp1), y = stoll(tmp2), z = stoll(s);
            if(z - x == y - z) cout << x << ' ' << y;
            else if(z - x < y - z) cout << x;
            else cout << y;
        }
    }
    return 0;
}