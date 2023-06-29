#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, ok = 1, a[15];
void ktao()
{
    for(int i = 1; i <= n; i++) a[i] = i;
}
void sinh()
{
    int i = n - 1;
    while(i >0 and a[i] > a[i + 1])
    {
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        int j = n;
        while(a[i] > a[j]) --j;
        swap(a[i],a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int main()
{
    faster();
    test()
    {
        cin >> n;
        ktao();
        while (ok)
        {
            /* code */
            for(int i = 1; i <= n; i++) cout << a[i];
            cout << ' ';
            sinh();
        }
        ok = 1;
        cout << endl;
    }
    return 0;
}