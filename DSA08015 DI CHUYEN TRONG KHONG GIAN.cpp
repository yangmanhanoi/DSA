#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
int a, b, c;
char s[55][55][55];
int visited[55][55][55] = {};
int trace[55][55][55] = {};
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
struct point
{
    int x, y, z;
};
point start, finish;
int bfs()
{
    queue<point> q;
    q.push(start);
    while(!q.empty())
    {
        point top = q.front();
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int x1 = top.x + dx[i];
            int y1 = top.y + dy[i];
            int z1 = top.z + dz[i];
            if(x1 >= 0 and x1 < a and y1 >= 0 and y1 < b and z1 >= 0 and z1 < c and (s[x1][y1][z1] == '.' or s[x1][y1][z1] == 'E') and !visited[x1][y1][z1])
            {
                //cout << top.x << ' '<< top.y << ' '<< top.z << endl;
                visited[x1][y1][z1] = 1;
                trace[x1][y1][z1] = trace[top.x][top.y][top.z] + 1;
                q.push({x1, y1, z1});
                if(x1 == finish.x and y1 == finish.y and z1 == finish.z) return trace[x1][y1][z1];
            }
        }
    }
    return -1;
}
int main()
{
    faster()
        test()
    {
        memset(visited, 0, sizeof(visited));
        memset(trace, 0, sizeof(trace));
        cin >> a >> b >> c;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int k = 0; k < c; k++)
                {
                    cin >> s[i][j][k];
                    if (s[i][j][k] == 'S')
                        start = {i, j, k};
                    else if (s[i][j][k] == 'E')
                        finish = {i, j, k};
                }
        // cout << start.x << ' ' << start.y << ' ' << start.z << endl;
        // cout << finish.x << ' ' << finish.y << ' ' << finish.z << endl;
        cout << bfs() << endl;
    }
    return 0;
}