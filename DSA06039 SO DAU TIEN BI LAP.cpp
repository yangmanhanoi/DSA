#include<bits/stdc++.h>
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
        int n; cin >> n;
        int a[n + 5];
        int ans = -1;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(mp[a[i]] > 1)
            {
                ans = a[i];
                break;
            }
        }
        if(ans == -1) cout << "NO";
        else cout << ans;
        cout << endl;
    }
    return 0;
}