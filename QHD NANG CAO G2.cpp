#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
ll mod = 1e9 + 7;
 
int main (){
    faster();
    int t; cin >> t;
    int idx = 1;
    while(t--){
        ll n;
        cin >> n;
        ll arr[n + 5][n + 5] = {};
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++) 
                cin >> arr[i][j];
        ll dp[20][3300] = {};
        for(ll i = 0; i <= n; i++)
            for(ll j = 0; j <= (1 << n); j++) 
                dp[i][j] = -1;
        for(ll i = 0; i < n;i++)
            dp[i][0] = 0;
        for(ll mask = 0; mask < (1 << n); mask++){
            ll dem = 0;
            for(ll i = 0; i < n; i++) if((mask & (1 << i)) == 0) dem++;
            //cout << mask << " " << n - dem << endl;
            for(ll i = 0; i < n; i++){
                if(dp[i][mask] >= 0)
                    for(ll j = 0; j < n; j++){
                        if((mask & (1 << j)) == 0)
                            dp[j][mask | (1 << j)] = max(dp[j][mask | (1 << j)], dp[i][mask] + arr[n - dem][j]);
                    }
            }
        }
        ll kq = 0;
        for(ll i = 0; i < n; i++) 
            if(kq < dp[i][(1 << n) - 1]) kq = dp[i][(1 << n) - 1];
        cout << "Case " << idx << ": " << kq << endl;
        idx++;
        //cout << dp[i][(1 << n) - 1] << " ";
    }

}