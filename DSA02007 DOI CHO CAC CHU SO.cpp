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
        string s; cin >> s;
        int a[10];
        for(int i = 0; i < s.size(); i++)
        {
            a[i] = s[i] - '0';
           // cout << a[i];
        }
        int cnt = 0;
        for(int i = 0; i < s.size() - 1; i++)
        {
            string tmp = s;
            int idx = i;
            for(int j = i + 1; j < s.size(); j++)
            {
                if((s[j] - '0') >= (s[idx] - '0')) idx = j;
            }
            if(cnt == n) break;
            if(idx != i)
            {
                swap(s[i], s[idx]);
                if(s != tmp) cnt++;  
            }
           // cout << s << " " << cnt << endl;
        }
        cout << s << endl;
    }
    return 0;
}