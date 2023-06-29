#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
char binSearch(int n, int k)
{
    int x = pow(2, n - 1);
    if(k == x) return n - 1 + 'A';
    if(k < x) return binSearch(n - 1, k);
    else return binSearch(n , k - x);
}
int main()
{
    faster()
    test()
    {
        int n, k; cin >> n >> k;
        cout << binSearch(n, k) << endl;
    }
    return 0;
}