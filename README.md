# ShortestPathDijkstra
Dijkstra算法求最短路径

求起点到终点最短路径，用Dijkstra算法实现并测试，
Dijkstra采用贪心策略，从已知当前最短路径扩展到邻接顶点最短路径，Dist[j] = min{ Dist[j], Dist[i]+graphy[i][j] }
其中Dist[j]为目前起点到顶点j的路径，Dist[i]为起点到顶点i的最短路径，graphy[i][j]为顶点i到顶点j的路径
