#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	int a[n];
	int v[n];
	for(int i = 1 ; i <= n; i++){
		cin>>a[i];
		v[a[i]]=i;
	}
	int j;
	int res = 0, cnt = 1;
	for(j = 1; j < n;j++)
	{
		while(v[j] < v[j+1])
		{
			++cnt;
			++j;
		}
		res = max(res, cnt);
		cnt = 0;
	}
	int ans = n - res;
	if(ans == -1) cout << 0;
	else cout << ans;
}