#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    faster()
    test()
    {
        string s; cin >> s;
        ll dp[20][4][7][3] = {};
        for(int i = 1; i <= 9; i++)
        {
            int r4 = (i == 4);
            int r7 = (i == 7);
            int x = s[0] - '0';
            // state = 0
            if(i < x)
            {
                dp[1][r4][r7][0]++;
            }
            //state = 1
            else if(i == x)
            {
                dp[1][r4][r7][1]++;
            }
            // state = 2
            else
            {
                dp[1][r4][r7][2]++;
            }
        }
        ll l = s.size();
        int newR4, newR7, newState;
        for(int i = 1; i < l; i++)
        {
            for(int r4 = 0; r4 < 4; r4++)
            {
                for(int r7 = 0; r7 < 7; r7++)
                {
                    for(int state = 0; state < 3; state++)
                    {
                        // Chuyển trạng thái tìm các trạng thái mới
                        for(int j = 0; j <= 9; j++)
                        {
                            newR4 = (r4  + (j == 4)) % 4;
                            newR7 = (r7 +  (j == 7)) % 7;
                            if(state == 1)
                            {
                                int x = s[i] - '0';
                                if(j < x) newState = 0;
                                else if(j == x) newState = 1;
                                else newState = 2;
                            }
                            else newState = state;
                            // cập nhật là số lượng cách có thể thêm j vào để nó vẫn giữ nguyên trạng thái
                            // ví đụ: 51j , 52j , 53j , 55j , 56j , 58j , 59j
                            // Tương đương số cách thêm j chính là số lượng số có 2 chữ số của trạng thái cũ
                            dp[i + 1][newR4][newR7][newState] += dp[i][r4][r7][state];
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <= l - 1; i++)
        {
            for(int state = 0; state < 3; state++)
            {
                ans += dp[i][0][0][state];
            }
        }
        for(int i = 0; i < 2; i++)
        {
            ans += dp[l][0][0][i];
        }
        cout << ans << endl;
    }
    return 0;
}