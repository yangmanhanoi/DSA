#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, k;
vector<string> res, tmp;
unordered_map<string,int> mp;
void print()
{
    for(int i = 0; i < k; i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
}
void Try(int i)
{
    if(res.size() == k)
    {
        print();
        return;
    }
    for(int k = i; k < tmp.size(); k++)
    {
    	if(mp[tmp[k]] == 0)
    	{
    		res.push_back(tmp[k]);
    		mp[tmp[k]]++;
	        Try(k + 1);
	        mp[res.back()]--;
	        res.pop_back();
    	}
        
    }

}
int main()
{
    faster()
    cin >> n >> k;
    set<string> s;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
        s.insert(vs[i]);
    }
    for(auto &i : s) tmp.push_back(i);
    Try(0);
    return 0;
}