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
        int n; cin >> n;
        // left: luu gia tri lon nhat tinh den phan tu do tinh ve ben trai
        // right: luu gia tri nho nhat tinh tu phai va k tinh gia tri do
        int a[n + 5], left[n + 5], right[n + 5];
        for(int i = 1; i <= n; i++) cin >> a[i];
        left[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            left[i] = max(a[i],left[i - 1]);
        }
        right[n] = a[n];
        for(int i = n - 1; i >= 1; i--)
        {
            right[i] = min(right[i + 1], a[i + 1]);
        }
        int cnt = 0;
        vector<int> vs;
        for(int i = 1; i <= n; i++)
        {
            if(left[i] <= right[i] and i != n)
            {
                cnt++;
                vs.push_back(i);
            }
        }
        cout << cnt << endl;
        if(vs.size() == 0) cout << endl;
        else
        {
            for(auto &i : vs) cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}