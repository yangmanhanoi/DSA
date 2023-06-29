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
        string s; cin >> s;
        int k; cin >> k;
        deque<char> dq;
        int check = 0;
        for(int i = 0; i < s.size(); i++)
        {
            while(!dq.empty() and s[i] < dq.front() and k > 0)
            {
                dq.pop_front();
                k--;
            }
            dq.push_front(s[i]);
        }
        while(k > 0)
        {
            dq.pop_front();
            k--;
        }
        string res = "";
        while(!dq.empty())
        {
            res += dq.back();
            dq.pop_back();
        }
//        cout << res << endl;
        int idx = 0;
        for(int i = 0; i < res.size(); i++)
        {
            while(res[i] == '0')
            {
                i++;
            }
            idx = i;
            break;
        } 
        if(idx == res.size()) cout << 0;
        else
        {
            for(int i = idx; i < res.size(); i++) cout << res[i];
        }
        cout << endl;
    }
    return 0;
}