#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<string> vs;
int main()
{
    faster();
    queue<string> q;
    q.push("4");
    q.push("7");
    vs.push_back("4"); vs.push_back("7");
    while(q.front().size() <= 10)
    {
        string top1 = q.front();
        q.pop();
        string top2 = q.front();
        q.pop();
        q.push(top1 + "4");
        q.push(top1 + "7");
        q.push(top2 + "4");
        q.push(top2 + "7");
        vs.push_back(top1 + "4"); vs.push_back(top1 + "7");
        vs.push_back(top2 + "4"); vs.push_back(top2 + "7");
    }
    int l, r;
    cin >> l >> r;
    ll ans = 0;
    ll res = l;
    for(auto &i : vs)
    {
        ll tmp = stoll(i);
        if(tmp > res and tmp <= r)
        {
            ans += tmp * (tmp - res + 1);
            res = tmp + 1;
        }
        else if(tmp == res)
        {
            ans += tmp;
            res = tmp + 1;
        }
        else if(tmp > r)
        {
            ans += tmp*(r - res + 1);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}