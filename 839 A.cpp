#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int a[2][2];
void rotate()
{
    int b[2][2];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    a[0][0] = b[1][0];
    a[0][1] = b[0][0];
    a[1][0] = b[1][1];
    a[1][1] = b[0][1];
}
int check()
{
    for(int i = 0; i < 2; i++)
    {
        if(a[i][0] >= a[i][1]) return 0;
        if(a[0][i] >= a[1][i]) return 0;
    }
    return 1;
}
int main()
{
    faster()
    test()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
        int n = 4;
        int flag = 0;
        while(n--)
        {
            if(check())
            {
                flag = 1;
                break;
            }
            rotate();
        }
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}