#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k, ok = 1;
void sinh(int a[])
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
        int a[1005];
        for(int i = 1; i <= k; i++) cin >> a[i];
        sinh(a);
        if(ok)
        {
            for(int i = 1; i <= k; i++) cout << a[i] << ' ';
        }
        else
        {
            for(int i = 1; i <= k; i++)
            {
                cout <<  i << ' ';
            }
        }
        cout << endl;
        ok = 1;
    }
    return 0;
}