# 强连通分量

有向图中，任意两个顶点互相可以连通，称为连通图

有向图的极大强连通子图称为强连通分量

## 朴素思路：

计算每个点可以到达的点，保存为一个大的数组reachable

reachable[i][j] 表示可以从i到达j

那么判断i，j是否在一个连通区域中，只需要判断是否 reachable[i][j] 和 reachable[j][i] 都成立

## 算法一：Kosaraju-Sharir algorithm

Fact: 把所有路径反转后的图，强连通图保持相同

思路：
1. 对原图G进行深度优先遍历，记录每个节点的离开时间。

2. 选择具有最晚离开时间的顶点，对反图GT进行遍历，删除能够遍历到的顶点，这些顶点构成一个强连通分量。

3. 如果还有顶点没有删除，继续step2，否则算法结束。

时间复杂度：$O(V+E)$

## 算法二：Path-Based Depth-First Search Algorithm



## 算法三：Tarjan算法