#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int n;
int mask[72];
ll f[2][72];
ll dp[2][1 << 20];
// Số nguyên tố
bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return 0;
	return 1;
}
// mask: biểu diễn trạng thái: bit 1 xuất hiện ở vị trí thứ k nếu số ngto thứ k xuất hiện khi phân tích số đó 2k + 1 lần
void init()
{
	for (int i = 0; i < 72; i++)
		f[0][i] = 1;
	int cnt = 0;
	for (int i = 2; i < 72; i++)
	{
		if (!prime(i))
			continue;
		for (int j = 1; j < 72; j++)
		{
			int x = j;
			while (x%i == 0)
			{
				x /= i;
				mask[j] ^= (1 << cnt);
			}
//			cout << j << ' ' << mask[j] << endl;
		}
		cnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	init();
	cin >> n;
	// f[0]: 
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		f[0][x] = f[1][x] = (f[0][x] + f[1][x]) % MOD;
	}
	dp[0][0] = 1;
	// Chỗ này e chưa hiểu rõ vì sao
	for (int i = 0; i <= 70; i++)
	{
		int nxt = (i + 1) % 2;
		int cur = i % 2;
		for (int msk = 0; msk < (1<<20); msk++)
		{
			dp[nxt][msk^mask[i]] = dp[nxt][msk^mask[i]] + dp[cur][msk] * f[1][i];
			dp[nxt][msk] = dp[nxt][msk] + dp[cur][msk] * f[0][i];
			if (dp[nxt][msk^mask[i]] >= MOD)
				dp[nxt][msk^mask[i]] %= MOD;
			if (dp[nxt][msk] >= MOD)
				dp[nxt][msk] %= MOD;
		}
		// ??
		for (int msk = 0; msk < (1<<20); msk++)
			dp[cur][msk] = 0;
	}
	cout << (dp[1][0] - 1 + MOD)%MOD << endl;
}