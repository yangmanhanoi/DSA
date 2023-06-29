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
int check(char s[])
{
    int l = strlen(s);
    for(int i = 0; i <= l/2; i++)
    {
        if(s[i] != s[l - 1 - i]) return 0;
    }
    return 1;
}
int max(int a,int b)
{
	if(a>b)  return a;
	else return b;
}
int main()
{
    faster()
    char s[100005];
    char a[1005][100005];
    int res = 0;
    int n = 0;
    while(scanf("%s", &s) != -1)
    {
        if(check(s))
        {
            strcpy(a[n++], s);
            res = max(res,strlen(s));
        }
    }
    int f[1005] = {};
    for(int i = 0; i < n; i++)
    {
        if(strlen(a[i]) == res and f[i] == 0)
        {
            int cnt = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(strlen(a[j]) == res and strcmp(a[i], a[j]) == 0)
                {
                    cnt++;
                    f[j] = 1;
                }
            }
            printf("%s %d\n", a[i], cnt);
        }
    }
    return 0;
}