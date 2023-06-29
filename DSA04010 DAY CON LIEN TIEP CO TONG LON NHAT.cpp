#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int crossingMid(int a[], int l, int mid, int r)
{
    int sum = 0;
    int maxLeft = INT_MIN;
    for(int i = mid; i >= l; i--)
    {
        sum += a[i];
        maxLeft = max(maxLeft, sum);
    }
    sum = 0;
    int maxRight = INT_MIN;
    for(int i = mid + 1; i <= r; i++)
    {
        sum += a[i];
        maxRight = max(maxRight, sum);
    }
    return max(max(maxLeft, maxRight), maxLeft + maxRight);
}
int subMax(int a[], int l, int r)
{
    if(l == r) return a[l];
    int mid = (l + r)/2;
    return max(max(subMax(a, l, mid), subMax(a, mid + 1, r)), crossingMid(a, l, mid, r));
}
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = n - 1;
        cout << subMax(a, l, r) << endl;
    }
    return 0;
}