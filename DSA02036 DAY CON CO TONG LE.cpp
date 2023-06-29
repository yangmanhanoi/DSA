#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
int a[20];
vector<int> vs;
vector<string> ans;
void Try(int i, int sum = 0)
{
    if(vs.size() > 0 and sum % 2 != 0)
    {
        string s = "";
        for(auto &i : vs)
        {
            string tmp = to_string(i);
            if(tmp.size() < 2) tmp = " " + tmp;
            s += tmp + " ";
        }
        ans.push_back(s);
    }
    for(int j = i; j <= n; j++)
    {
        vs.push_back(a[j]);
        Try(j + 1, sum + a[j]);
        vs.pop_back();
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
       // for(int i = 1; i <= n; i++) cout << a[i] << ' ';
        Try(1);
       // for(auto &i : ans) cout << i << endl;
        sort(ans.begin(), ans.end());
       // for(auto &i : ans) cout << i << endl;
        for(auto &i : ans)
        {
            stringstream ss(i);
            while(ss >> i)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        vs.clear();
        ans.clear();
    }
    return 0;
}