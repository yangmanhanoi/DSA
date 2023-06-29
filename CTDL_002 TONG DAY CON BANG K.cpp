#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k, ok = 1;
int a[25];
string s = "";
vector<string> vs;
void ktao()
{
    for(int i = 0; i < n; i++)
    {
        s += "0";
    }
}
void sinh()
{
    int i = n - 1;
    while(i >= 0 and s[i] == '1')
    {
        --i;   
    }
    if(i == -1) ok = 0;
    else
    {
        s[i] = '1';
        for(int j = i + 1; j < n; j++)
        {
            s[j] = '0';
        }
    }
}
int check()
{
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            cnt += a[i];
        }
    }
    if(cnt == k) return 1;
    else return 0;
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    ktao();
    while(ok)
    {
        if(check())
        {
            vs.push_back(s);
        }
        sinh();
    }
    for(int i = 0; i < vs.size(); i++)
    {
        for(int j = 0; j < vs[i].size(); j++)
        {
            if(vs[i][j] == '1')
            {
                cout << a[j] << ' ';
            }
        }
        cout << endl;
    }
    cout << vs.size() << endl;
    return 0;
}