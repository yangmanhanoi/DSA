#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
string s;
struct node
{
    int lenMax, open, close;
    // lenMax: luu doan ngoac dung dai nhat
    // open: luu so ngoac mo ma chua duoc ghep 
    // close: luu so ngoac dong ma chua duoc ghep
    node operator+(node &x)
    {
        node tmp;
        int res = min(this->open, x.close);
        tmp.lenMax = this->lenMax + x.lenMax + res;
        tmp.close = this->close + x.close - res;
        tmp.open = this->open + x.open - res;
        return tmp;
    }
};
node ST[4000005];
void buildTree(int idx, int l, int r)
{
    if(l == r)
    {
        if(s[l] == '(')
        {
            ST[idx] = {0, 1, 0};
            return;
        }
        else
        {
            ST[idx] = {0 ,0, 1};
            return;
        }
    }
    int mid = (l + r) >> 1;
    buildTree(idx << 1, l, mid);
    buildTree((idx << 1) + 1, mid + 1, r);
    ST[idx] = ST[idx << 1] + ST[(idx << 1) + 1];
}
node getResult(int idx, int L, int R, int lq, int rq)
{
    if(L > rq or R < lq) return {0,0,0};
    if(lq <= L and R <= rq) return ST[idx];
    int mid = (L + R) >> 1;
    node left = getResult(idx << 1, L, mid, lq, rq);
    node right = getResult((idx << 1) + 1, mid + 1, R, lq, rq);
    return left + right; 
}
int main()
{
    faster()
    int q;
    cin >> s >> q;
    s = '*' + s;
    int n = s.size();
    buildTree(1, 1, n);
    while(q--)
    {
        int x, y; cin >> x >> y;
        cout << getResult(1, 1, n, x, y).lenMax * 2 << endl;
    }
    return 0;
}