#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, x;
int a[10000005];
int minSearch(int l, int r)
{
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        if(l == r) return mid;
        else if(a[mid] < a[r])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
}
int binSearch(int l, int r)
{
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        if(a[mid] == x) return mid;
        else if(a[mid] > x)
        {
            r = mid - 1;
        }
        else l = mid + 1;
    }
}
int main()
{
    faster();
    test()
    {
        cin >> n >> x;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int l = 1, r = n;
        int minPos = minSearch(l, r);
//        cout << minPos << endl;
        int ans;
        if(x > a[n])
        {
            ans = binSearch(1, minPos - 1);
        }
        else ans = binSearch(minPos, n);
        cout << ans << endl;
    }
    return 0;
}