#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k, ok = 1;
int a[20];
void ktao()
{
    for(int i = 1; i <= k; i++) a[i] = i;
}
void sinh()
{
    int i = k;
    while(i > 0 and a[i] == n - k + i)
    {
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        a[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    faster();
    test()
    {
        cin >> n >> k;
        ktao();
        while (ok)
        {
            /* code */for(int i = 1; i <= k; i++) cout << a[i];
            cout << ' ';
            sinh();
        }
        ok = 1;
        cout << endl;
    }
    return 0;
}