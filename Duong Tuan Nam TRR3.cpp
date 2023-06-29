#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n;
int visited[15]= {};
vector<int> vs;
void Try(int i)
{
    if(vs.size() == n)
    {
        for(int i = 0; i < n; i++) cout << vs[i] << ' ';
    }
    for(int j = 1; j <= n; j++)
    {
        if(!visited[j])
        {
            vs.push_back(j);
            Try(i + 1);
            visited[j] = 1;
            vs.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    Try(0);
    return 0;
}