#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
int a[1005];
void sinh()
{
    int i = k;
    while(a[i] - a[i -1] == 1) --i;
    if(i == 0)
    {
        for(int j = 1; j <= k; j++) a[j] = n - k + j;
    }
    else
    {
        a[i]--;
        for(int j = i + 1; j <= k; j++)
        {
            a[j] = n - k + j;
        }
    }
}
void in()
{
    for(int i = 1; i <= k; i++) cout << a[i] << ' ';
}
int main()
{
    faster()
    test()
    {
        cin >> n >> k;
        for(int i = 1; i <= k; i++) cin >> a[i];
        a[0] = 0;
        sinh();
        in();
        cout << endl;
    }
    return 0;
}