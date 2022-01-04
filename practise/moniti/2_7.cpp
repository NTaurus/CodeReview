#include "../base.h"
#include <iostream>
using namespace std;
typedef long long ll;
int visit[maxn];
bool isvalid(ll num)
{
    int is[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (num)
    {
        int r = num % 10;
        if (is[r] || visit[r] || r == 0)
            return false;
        is[r] = 1;
        num /= 10;
    }
    return true;
}
/*
    算法思想：使用回溯算法
    1.每次选择1~9的数字拼凑起来，选择的数字必须是之前未选择的。
    2.将分子乘以三得到分母。
    3.再判断分母的合法性，分母合法的条件为：分母中的数字无重复，且与分子中的数字
    也不重复，且没有数字0
    4.若当前组合得到的分子和分母合法，则继续递归重复（1~3）步骤
*/
void dfs(ll FZ, ll FM)
{
    // if(FZ)cout<<FZ<<' '<<FM<<' '<<FZ*1.0/(FM*1.0)<<endl;
    if (FZ)
        printf("%-5d %-5d\n", FZ, FM);
    for (int i = 1; i < 10; i++)
    {
        if (visit[i] == 0)
        {
            FZ = FZ * 10 + i;
            visit[i] = 1;
            if (isvalid(FZ * 3))
            {
                dfs(FZ, FZ * 3);
            }
            visit[i] = 0;
            FZ = (FZ - i) / 10;
        }
    }
}
int main()
{
    dfs(0, 3);
    return 0;
}
