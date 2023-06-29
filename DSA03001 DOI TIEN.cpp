#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int fx[10] = {1,2,5,10,20,50,100,200,500,1000};
int main()
{
    faster()
    test()
    {
        int n; cin >> n;
        int cnt = 0;
        for(int i = 9; i >= 0; i--)
        {
            int tmp = 0;
            if(n >= fx[i])
            {
                tmp = n / fx[i];
                n -= tmp*fx[i];
            }
            cnt += tmp;
        }
        cout << cnt << endl;
    }
    return 0;
}