# 最大流算法



## S-T minimum cut

对于有向有权图，存在：

A minimun s-t cut is a cut which separates s from t with minimum cost. Here, the cost of a cut is the sum of the capacities of the edges that cross the cut.

将s和t分开，对于这个有向有权图来说，最小的s-t分割就是使得被割的边权重和最小的割法。



## S-T maximum flows

The value of a flow is the amount of stuff coming out of s (aka the amount of stuff flowing into t, due to flow conservation).

- Capacity Constraint: The flow on any edge must be less than its capacity.
- Flow Conservation Constaint: At each vertex, the incoming flows must equal the outgoing flows.

从S出发，能够发出来的最大流量是多少。要满足，每个节点流入流出相等，每条边不超过容量上限，



## Max-flow and Min-cut theorem

Theorem: the value of a max-flow from s to t is equal to the cost of a min s-t cut.

直觉想法：在最大流中，经过最小割的边会先被填满，从而形成一个瓶颈，导致无法再发出更多的流量。

证明：

1. 先证
   $$
   \text{value of max flow} \le \text{cost of min cut}
   $$
   所有从S出发的流，为了最终到达T，一定要经过最小割，所以必然比它小。

2. 再证
   $$
   \text{value of max flow} \ge \text{cost of min cut}
   $$
   使用Ford-Fulkerson算法来证明，详见下一节。



## Ford-Fulkerson Algorithm

### 伪代码：

Ford-Fulkerson(G, s, t)
1. Start with arbitrary flow f.
2. Construct residual graph $G_f$.
3. Check if there's a path in $G_f$ from s to t:
   - if there is a path, Update_Flow(P, f), and go back to step 2.
   - if there isn't a path, then f is the max flow!



Update_Flow(path P in $G_f$ , flow $f$ )

x = min weight on any edge in P from $G_f$.

for (u, v) in P:

​	if (u, v) in E: $f_{new}(u, v) = f(u, v) + x$

​	if (v, u) in E: $f_{new}(u, v) = f(u, v) - x$

return $f_{new}$



### 算法过程举例：

![image-20211123223752295](https://i.loli.net/2021/11/23/NC4rBLoKQ9edMOA.png)

当前，已知图G和上一迭代过程f，此时需要计算两个过程：

- Forward Edges：每条边上剩下的流量
- Backward Edges：每条边上已经用的流量



### 时间复杂度分析



## 应用：礼物匹配

问题描述：有一堆学生和一堆礼物，每个学生有自己偏爱的一些礼物，但是每种礼物只有一种。获得一个礼物的学生就会满足。怎么分配来满足最多学生的要求？

<img src="https://i.loli.net/2021/11/23/aX1kBNA9gMlcisV.png" alt="image-20211123221543049" style="zoom: 50%;" />

转化为一个最大流的问题，在左右两端分别添加一个结点作为S和T，计算S到T的最大流就是最优结果。

![image-20211123221750004](https://i.loli.net/2021/11/23/TBZ8VFdfbptmKP6.png)

