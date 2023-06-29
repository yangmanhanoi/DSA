#include<bits/stdc++.h>
using namespace std;
int n, k, a[1005],cnt = 0, ok = 1;
#define test() int t; cin >> t; while(t--)
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    test()
    {
        vector<int> s1;
        cin >> n >> k;
        for(int i = 1; i <= k; i++) cin >> a[i];
        unordered_map<int,int> mp;
        for(int i = 1; i <= k; i++)
        {
            mp[a[i]]++;
        }
        int i = k;
        while(i >= 1 and a[i] == n - k + i)
        {
            --i;
        }
        if(i == 0) cout << k << endl;
        else
        {
            a[i]++;
            for(int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1] + 1;
            }
            for(int i = 1; i <= k; i++)
            {
                if(mp[a[i]] == 0) cnt++;
            }
            cout <<  cnt << endl;
        }
        cnt = 0; 
    }
    return 0;
}