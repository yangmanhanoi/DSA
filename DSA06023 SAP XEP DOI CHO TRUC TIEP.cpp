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
        vector<string> vs;
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1; i++)
        {
 //           cout << "Buoc " << i + 1 << ": ";
            
            for(int j = i + 1; j < n; j++)
            {
                if(a[i] > a[j]) swap(a[i], a[j]);
            }
            string s = "";
            for(int k = 0; k < n; k++) s += to_string(a[k]) + " ";
            vs.push_back(s);
        }
        for(int i = vs.size() - 1; i >= 0; i--)
        {
            cout << "Buoc " << i + 1 << ": ";
            cout << vs[i];
            cout << endl;
        }
    }
    return 0;
}