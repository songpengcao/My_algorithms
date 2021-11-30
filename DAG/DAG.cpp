// 判断一个图是不是有向无环图(DAG)
// 主要思路：dfs过程中，判断下一个要遍历的点有没有在当前这条线路上

#include <iostream>

using namespace std;

int graph[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,1,1,0,0},
    {0,1,0,0,0,0,1,1},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0}
};

int permutation[7] = {3,2,4,5,7,6,1};

int visited[8] = {0};
// 0 代表没走过
// -1 代表走过，但是不是这次走的
// 1 代表这次走的

bool flag=true;  // this graph is a DAG


void dfs(int x)
{
    visited[x] = 1;
    for (int next_node = 1; next_node <= 7; next_node ++)
    {
        if (graph[x][next_node] == 1)
        {
            if (visited[next_node] == 0) dfs(next_node);
            else if (visited[next_node] == 1)
            {
                flag = false;  // find a cycle
                cout << x << ' ' << next_node << endl;
            }
        }
    }
    visited[x] = -1;
    return;
}

int main()
{
    for (int i = 0; i < 7; i ++)
    {
        int next_node = permutation[i];
        if (visited[next_node] == 0) dfs(permutation[i]);
    }
    cout << flag << endl;
    return 0;
}