#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int q, n;
int a[10005] = {};
int ST[40005] = {}, lazy[40005] = {};
// void pushDown(int idx)
// {
//     ST[idx << 1] = lazy[idx];
//     ST[(idx << 1) + 1] = lazy[idx];
//     lazy[idx << 1] = lazy[idx];
//     lazy[(idx << 1) + 1] = lazy[idx];
//     lazy[idx] = 0;
// }
// void update(int idx, int lq, int rq, int l, int r, int val)
// {
//     if(r < lq or l > rq) return;
//     if(lq <= l and r <= rq)
//     {
//         ST[idx] = val;
//         lazy[idx] = val;
//        return;
//     }
//     int mid = (l + r) / 2;
//     pushDown(idx);
//     update(idx << 1, lq, rq, l, mid, val);
//     update((idx << 1) + 1, lq, rq, mid + 1, r, val);
// }
// set<int> s;
// void getResult(int idx, int l, int r)
// {
//     if(l == r)
//     {
//         if(ST[idx] > 0) s.insert(ST[idx]);
//         return;
//     }
//     int mid = (l +r) / 2;  
//     pushDown(idx);
//     getResult(idx << 1, l , mid);
//     getResult((idx << 1) + 1, mid + 1, r);
// }
int main()
{
    faster()
    test()
    {
        set<int> s;
        memset(ST, 0, sizeof(ST));
        memset(lazy, 0, sizeof(lazy));
        cin >> q >> n;
        int a[n + 5] = {};
        for(int i = 1; i <= q; i++)
        {
            int x, y; cin >> x >> y;
            for(int j = x; j <= y; j++) a[j] = i;           // update(1, x, y, 1, n, i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i] > 0) s.insert(a[i]);
        }
       // for(int i = 1; i <= 20; i++) cout << ST[i] << ' '; 
       // getResult(1, 1, n);
        cout << s.size() << endl;
        s.clear();
    }
    return 0;
}