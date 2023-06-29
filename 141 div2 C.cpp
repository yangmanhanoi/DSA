#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
// so sanh nho hon a <= b   
bool compare(string a, string b)
{
    if(a.size() > b.size())
    {
        if(a.substr(0, b.size()) == b) return 0;
    }
    if(b.size() > a.size())
    {
        if(b.substr(0, a.size()) == a) return 1;
    }
    return a <= b;
}
int main()
{
    faster()
    cout << compare("b", "bb") << endl;
    test()
    {
       string s;
       cin >> s;
       string a, b, c;
       int check = 0;
       for(int i = 1; i <= s.size() - 2; i++)
       {
        a = s.substr(0, i);
            for(int j = s.size() - i - 1; j >= 1; j--)
            {
                b = s.substr(i, j);
                c = s.substr(i + j);
                if((compare(a, b) and compare(c, b)) or (compare(b, a) and compare(b, c)))
                {
                    check = 1;
                    break;
                }
            }
       }
       if(check) cout << a << ' ' << b << ' ' << c << endl;
       else cout << ": (" << endl;
    }
    return 0;
}