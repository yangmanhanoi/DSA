#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, cnt = 0;
int column[15] = {}, diagonal1[40] = {}, diagonal2[40] = {}, x[15];
void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(column[j] == 0 and diagonal1[i - j + n] == 0 and diagonal2[i + j - 1] == 0)
        {
            column[j] = diagonal1[i - j + n] = diagonal2[i + j - 1] = 1;
            x[i] = j;
            if(i == n)
            {
                cnt++;
            }
            Try(i + 1);
            column[j] = diagonal1[i - j + n] = diagonal2[i + j - 1] = 0;
        }
    }
}
int main()
{
    faster()
    test()
    {
        memset(column, 0, sizeof(column));
        memset(diagonal1, 0, sizeof(diagonal1));
        memset(diagonal2, 0, sizeof(diagonal2));
        cin >> n;
        Try(1);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}