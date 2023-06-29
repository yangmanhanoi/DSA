#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[100005];
int binSearch(int l, int r,int k)
{
    int pos = -1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] == k)
        {
            pos = mid;
            break;
        }
        else if(a[mid] > k) r= mid - 1;
        else l = mid + 1;
    }
    return pos;
}
int main()
{
    faster()
    test()
    {
        int n, k; cin >> n >> k ;
        for(int i = 0; i < n; i++) cin >> a[i];
        int pos = binSearch(0, n - 1, k);
        if(pos == -1) cout << "NO";
        else cout << pos + 1;
        cout << endl;
    }
    return 0;
}