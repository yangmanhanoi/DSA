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
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int minPos = i;
            for(int j = i + 1; j < n; j++)
            {
                if(a[j] < a[i]) minPos = j;
            }
            if(minPos != i)
            {
                swap(a[minPos], a[i]);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}