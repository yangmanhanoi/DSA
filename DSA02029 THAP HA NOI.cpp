#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
vector<string> vs;
void Try(int i, char a, char b, char c)
{
    if(i == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    else
    {
        // Chuyen i - 1 dia sang coc B
        Try(i - 1, a, c, b);
        // Chuyen dia cuoi cung sang coc dich C
        Try(1, a, b, c);
        // Chuyen i - 1 dia tu coc B sang coc dich C
        Try(i - 1, b, a, c);
    }
}
int main()
{
    faster()
    cin >> n;
    Try(n, 'A', 'B', 'C');
    return 0;
}