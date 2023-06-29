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
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        int cnt = 0;
        int min_col = min(y, t);
        int max_col = max(y, t);
        int min_hang = min(x, z);
        int max_hang = max(x, z);
        if(min_col == max_col)
        {
            cnt += max_hang - min_hang;
        }
        else if(min_hang == max_hang)
        {
            cnt += max_col - min_col;
        }
        else
        {
            int tmp1 = 0, tmp2 = 0;
            tmp1 += max_hang - min_hang;
            int tmp = min_col + tmp1;
            tmp1 += max_col - tmp;
            tmp2 += max_col - min_col;
            tmp = min_hang + tmp2;
            tmp2 += max_hang - tmp;
            cnt = min(tmp1, tmp2);
        }
        cout << cnt << endl;
    }
    return 0;
}