#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int idx7 = n / 7, idx4 = n / 4;
        int res1, res2;
        res1 = res2 = 0;
        int check = 0;
        for(int i = idx7; i >= 0; i--)
        {
            if((n - 7*i) % 4 == 0)
            {
                check = 1;
                res1 = (n - 7*i)/4;
                res2 = i;
                break;
            }
        }
        if(!check) cout << -1;
        else
        {
            for(int i = 0; i < res1; i++) cout << 4;
            for(int i = 0; i < res2; i++) cout << 7;
        }
        cout << endl;
    }
    return 0;   
}