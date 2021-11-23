# 最小割算法



## 什么是割？

A cut is a partition of the vertices into two nonempty parts.

即把一个图G=(V,E)的节点分割为两个部分S和V-S。

![image-20211123155259895](https://i.loli.net/2021/11/23/Ly1NszHr8TteOSq.png)



A (global) minimun cut is a cut that has the fewest edges possible corssing it.

全局最小割就是在割成两个部分的同时使得断开的边最少。（对于无向无权的图）



## 有什么用？

- 社交网络中的聚类问题
- 图像分割



## 两种随机算法的引入

- Las Vegas Algorithms：保证正确，不保证时间（例如快排）
- Monte Carlo Algorithms：保证时间，不保证正确（Karger算法）



## Karger's Algorithm

每次随机选择一条边，将这条边上的两个节点合并成一个super-node，原来与这两个点邻接的点，现在把边连到合并后super-node上面去，再把原来的点和边删除。

然后重复这个过程，直到只剩下两个节点，这两个点之间的边数就是形成割的边数，并且可以对应回到原图上的边，这两个super-node中的节点就是割后的两个类。

### 时间复杂度分析





### 正确性分析

这个算法成功的概率为$Pr(success) \ge \frac{1}{C_n^2}$

证明：





### 怎么减少时间复杂度？

Karger 算法可以达到$O(n^2log^2n)$ 的复杂度。

目前的做法是每次从头开始算法，但可以发现，从头开始时备选的edge更多，从而选到
