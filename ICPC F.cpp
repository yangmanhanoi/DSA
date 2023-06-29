#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define ll long long
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long a;
    cin >> a;
    int check = 1;
    int l = sqrt(2) * a / 2;
    for ( int i = 1; i <= l; i++ )
    {
        long long d = 2 * a * a - i * i;
        if ( d > 0 )
        {
            long long tmp = sqrt(d);
            if ( tmp * tmp == d && tmp != i && tmp != a and a != i)
            {
                check = 0;
                break;
            }
        }
    }
    if ( check ) cout << "NO";
    else cout << "YES";
    return 0;
}