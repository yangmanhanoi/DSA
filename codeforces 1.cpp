#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
vector<string> vs;
int main()
{
    faster()
    //     string str = "Yes";
    // vs.push_back("Yes");
    // vs.push_back("es");
    // vs.push_back("Ye");
    // vs.push_back("Y");
    // vs.push_back("e");
    // vs.push_back("s");
    // string x = "";
    // for(int i = 1; i <= 50; i++)
    // {
    //     x += "Yes";
    // }
    // test()
    // {
    //     string s;
    //     cin >> s;
    //     if(x.find(s) != string::npos) cout << "YES\n";
    //     else cout << "NO\n";
    // }
    // return 0;
    // int b[105] = {};
    // b[1] = 1;
    // for(int i = 2; i <= 100; i++)
    // {
    //     b[i] = b[i - 1] + i;
    // }
    // test()
    // {
    //     int m, s; cin >> m >> s;
    //     int a[m + 5];
    //     int sum = 0;
    //     int idx = 0;
    //     for(int i = 0; i < m; i++)
    //     {
    //         cin >> a[i];
    //         if(idx < a[i]) idx = a[i];
    //         sum += a[i];
    //     }
    //     sum += s;
    //     int check = 0;
    //     for(int i = 100; i >= 1; i--)
    //     {
    //         if(i >= idx)
    //         {
    //             if(sum == b[i])
    //             {
    //                 check = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     if(check) cout << "YES\n";
    //     else cout << "NO\n";
    test()
    {
        int l, r, x; cin >> l >> r >> x;
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        int ans;
        int res = b - a;
        if(b - a >= x) ans = 1;
        else
        {
            int res1, res2;
            int tmp1 = a, tmp2 = b;
            if((r - tmp1 >= x) or (tmp2 - l >= x)) ans = 2;
            else
            {
                
            }
        }
        

    }
    return 0;
}