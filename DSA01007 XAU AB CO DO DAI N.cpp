#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, ok = 1;
string s = ""; 
vector<string> vs;
void ktao()
{
    for(int i = 0; i < n; i++) s += 'A';
}
void sinh()
{
    int i = n - 1;
    while(i >= 0 and s[i] == 'B')
    {
        --i;
    }
    if(i == -1) ok = 0;
    else
    {
        s[i] = 'B';
        for(int j = i + 1; j < n; j++) s[j] = 'A';
    }
}
int main()
{
    faster();
    test()
    {
        cin >> n;
        ktao();
        while(ok)
        {
            for(int i = 0; i < n; i++) cout << s[i];
            cout << ' ';
            sinh();
        }
        ok = 1;
        cout << endl;
        s = "";
    }
    return 0;
}