#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,k,a[20], cnt = 0;
void print()
{
    cout << "[";
    for(int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v.back() << "]";
}
void Try(int i, int sum = 0)
{
    if(sum > k) return;
    if(sum == k)
    {
        print();
        cnt++;
        return;
    }
    for(int j = i; j <= n; j++)
    {
        v.push_back(a[j]);
        Try(j, sum + a[j]);
        v.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t; while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a+1,a+n+1);
        Try(1);
        if(cnt == 0) cout << -1;
        cout << endl;
        v.clear();
    }
    return 0;
}