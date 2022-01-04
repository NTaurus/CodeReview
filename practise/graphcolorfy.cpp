#include <iostream>
using namespace std;
const int maxn = 100;
bool visit[maxn][maxn];
int G[maxn][maxn];
int N, sr, sc, m, scolor;
int Color[5] = {1, 2, 3, 4, 5};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
//尝试用栈来模拟递归解决回溯问题
bool isvalid(int r, int c)
{
    if (r < 0 || r >= N || c < 0 || c >= N)
        return false;
    return true;
}
bool iscolor(int color, int r, int c)
{
    if (isvalid(r - 1, c) && G[r - 1][c] == color)
        return false;
    if (isvalid(r + 1, c) && G[r + 1][c] == color)
        return false;
    if (isvalid(r, c - 1) && G[r][c - 1] == color)
        return false;
    if (isvalid(r, c + 1) && G[r][c + 1] == color)
        return false;
    return true;
}
void colorfy(int r, int c, int color)
{
    // if (m >= N * N)
    {
        cout<<m<<' '<<N*N<<endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", G[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        // return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tr = r + dx[i];
        int tc = c + dy[i];
        if (isvalid(tr, tc) && visit[tr][tc] == false)
        {
            visit[tr][tc] = 1;
            for (int j = 0; j < 5; j++)
            {
                if (iscolor(Color[j], tr, tc))
                {
                    G[tr][tc] = Color[j];
                    m++;
                    colorfy(tr, tc, Color[j]);
                    // G[tr][tc] = 0;
                    m--;
                }
            }
            visit[tr][tc] = 0;
        }
    }
}
int main()
{
    cin >> N >> sr >> sc >> scolor;
    m = 1;
    visit[sr][sc] = 1;
    G[sr][sc] = scolor;
    colorfy(sr, sc, scolor);
    return 0;
}