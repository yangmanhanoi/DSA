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
        int n, k; cin >> n >> k;
        vector<int> v(n);
        int f[1005] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            f[v[i]]++;
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int tmp = k - v[i];
            if(tmp < 0) continue;
            else
            {
                if(binary_search(v.begin() + i,v.end(),tmp))
                {
                    if(tmp * 2 == k)
                    {
                        cnt += (f[tmp] - 1)*f[tmp]/2;
                        f[tmp] = 0;
                    }
                    else cnt += f[tmp];
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}