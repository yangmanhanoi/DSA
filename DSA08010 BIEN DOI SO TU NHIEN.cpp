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
        ll n; cin >> n;
        queue<ll> q;
        map<ll, int> m;
        q.push(n);
        m[n]++;
        while(!q.empty())
        {
            ll top = q.front();
            q.pop();
            int sqr = sqrt(top);
            for(int i = sqr; i >= 2; i--)
            {
                if(top % i == 0)
                {
                    int tmp = top / i;
                    if(m[tmp] == 0)
                    {
                        q.push(tmp);
                        m[tmp] = m[top] + 1;
                    }
                }
            }
            if(m[top - 1] == 0)
            {
                q.push(top - 1);
                m[top - 1] = m[top] + 1;
            }
            if(m[1] > 0)
            {
                cout << m[1] - 1 << endl;
                break;
            }
        }
    }
    return 0;
}