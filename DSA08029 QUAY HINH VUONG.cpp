#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
class Matrix{
    public:
        int a[2][3];
        int cnt;
    public:
    Matrix()
    {
        this->cnt = 0;
    }
    friend istream& operator >> (istream& is, Matrix &x)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                is >> x.a[i][j];
            }
        }
        return is;
    }
    Matrix nuaTrai(Matrix x)
    {
        Matrix d = x;
        d.a[0][0] = x.a[1][0];
        d.a[0][1] = x.a[0][0];
        d.a[1][0] = x.a[1][1];
        d.a[1][1] = x.a[0][1];
        return d;
    }
    Matrix nuaPhai(Matrix x)
    {
        Matrix d = x;
        d.a[0][1] = x.a[1][1];
        d.a[0][2] = x.a[0][1];
        d.a[1][1] = x.a[1][2];
        d.a[1][2] = x.a[0][2];
        return d;
    }
};
map<string, int> mp;
Matrix n, m;
string firstElement(Matrix x)
{
    string tmp = "";
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tmp += to_string(x.a[i][j]);
        }
    }
    return tmp;
}
bool check(Matrix x)
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(m.a[i][j] != x.a[i][j]) return 0;
        }
    }
    return 1;
}
int bfs()
{
    queue<Matrix> q;
    q.push(n);
    while(!q.empty())
    {
        Matrix top = q.front();
        q.pop();
        Matrix tmp = top.nuaPhai(top);
        string s = firstElement(tmp);
        if(mp[s] == 0)
        {
            mp[s]++;
            tmp.cnt = top.cnt + 1;
            q.push(tmp);
            if(check(tmp)) return tmp.cnt;
        }
        tmp = top.nuaTrai(top);
        s = firstElement(tmp);
        if(mp[s] == 0)
        {
            mp[s]++;
            tmp.cnt = top.cnt + 1;
            q.push(tmp);
            if(check(tmp)) return tmp.cnt;
        }
    }
}
int main()
{
    faster()
    test()
    {
        cin >> n >> m;
        cout << bfs() << endl;
        mp.clear();
    }
    return 0;
}