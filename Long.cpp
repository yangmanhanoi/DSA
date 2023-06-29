#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<string> vs(20);
vector<string> v;
set<string> ans;
void print()
{
    string s = "";
    for(int i = 0; i < v.size(); i++) s += v[i];
    ans.insert(s);
}
void Try(int i)
{
    if(v.size() == k)
    {
        print();
        return;
    }
    for(int j = i; j < n; j++)
    {
        v.push_back(vs[j]);
        Try(j + 1);
        v.pop_back();
        
    }
}
int main()
{
	cin >> n;
    for(int i = 0; i < n; i++) cin >> vs[i];
    //sort(vs.begin(), vs.begin() + n);
    //for(int i = 0; i < n; i++) cout << vs[i] << ' ';
    for(k = 1; k <= n; k++)
    {
        Try(0);

    }
    for(auto i : ans) cout << i << endl;
    return 0;
}