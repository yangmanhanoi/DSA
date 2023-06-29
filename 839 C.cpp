#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
        test()
    {
        int k, n;
        cin >> k >> n;
        vector<int> vs;
        vs.push_back(1);
        int cnt = 1;
        for(int i = 1; i <= k; i++)
        {
            if(n - vs.back() - cnt >= k - vs.size() - 1 and vs.back() + cnt <= n)
            {
                vs.push_back(vs.back() + cnt);
                cnt++;
                if(vs.size() == k) break;
            }
        }
        while(vs.size() < k)
        {
            vs.push_back(vs.back() + 1);
        }
        for(int i : vs) cout << i << ' ';
        cout << endl;
    }
    return 0;
}