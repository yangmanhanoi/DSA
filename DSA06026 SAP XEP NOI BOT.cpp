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
        for(int i = 0; i < n; i++)
        {
            string s = "";
            int check = 0;
            for(int j = 0; j < n - 1; j++)
            {
                if(a[j + 1] < a[j])
                {
                    swap(a[j],a[j + 1]);
                    check = 1;
                }
            }
            if(!check) break;
            else
            {
                for(int i = 0; i < n; i++) s += to_string(a[i]) + " ";
                vs.push_back(s);
            }
        }
        for(int i = vs.size() - 1; i >= 0; i --)
        {
            cout << "Buoc " << i + 1 << ": ";
            cout << vs[i] << endl;
        }
    }
    return 0;
}