# 图的可达性

问题定义：对于一个有向无权图，有两个节点$u$, $v$，是否存在一条路径可以$u \rightarrow v$?

## 朴素思想

- DFS
- BFS

时间复杂度过高，最坏情况需要访问图里所有的节点。

## Index-based methods

There is a trade-off between indexing time and query time.

- Transitive closure

    - Run the Floyd-Warshall algorithm and store all possible query results in a matrix

    - 时间复杂度(indexing)：$O(n^3)$

    - 空间复杂度(indexing)：$O(n^2)$

    - 查询时间：$O(1)$

    ```c++
    booltc[num_vertices][num_vertices];
    // Initialize the matrix tc: O(n^2)
    tc[i][j] = 1 if there is an edge from ito j, or i== j;
    // Run Floyd-Warshall
    for (int k = 0; k < num_vertices; ++k)
    {
        for (int i= 0; i< num_vertices; ++i)
        {
            for (int j = 0; j < num_vertices; ++j)
            {
                tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);
                //d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
            }
        }
    }
    ```
- Tree over

    - Use spanning trees to store the reachability information that is originally stored in transitive closure in hierarchy

    - 对于一个树形的DAG，首先后序遍历，记录遍历的序号

- 2-hop labeling

    - For each node in the graph, assign two label sets for it to store the reachability information that is originally stored in transitive closure

    - 如果一个节点$u$，可以到达$v$，那么$u$的所有祖先都可以到达节点$v$。