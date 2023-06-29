#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<string> ans;
vector<string> tmp;
int n;
string str;
int main()
{
    cin >> n;
    vector<string> vs(n + 5);
    set<string> s;
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    cin >> str;
    for(int i = 0; i < n; i++)
    {
        if(vs[i] != str) s.insert(vs[i]);
    }
    for(auto &i : s)
    {
       tmp.push_back(i);
    }
    do
    {
        /* code */
        for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << ' ';
        cout << str << ' ';
        cout << endl;
    } while (/* condition */next_permutation(tmp.begin(), tmp.end()));
    
//    Try(0);
    return 0;
}