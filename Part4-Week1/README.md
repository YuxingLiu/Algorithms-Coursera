# Algorithm-Part4-Week1
Bellman-Ford algorithms, all-pairs shortest paths.

## Problem 1
In this assignment you will implement one or more algorithms for the all-pairs shortest-path problem. Here are data files describing three graphs:
[g1.txt](https://github.com/YuxingLiu/Algorithms-Coursera/blob/master/Part4-Week1/g1.txt),
[g2.txt](https://github.com/YuxingLiu/Algorithms-Coursera/blob/master/Part4-Week1/g2.txt),
[g3.txt](https://github.com/YuxingLiu/Algorithms-Coursera/blob/master/Part4-Week1/g3.txt).

The first line indicates the number of vertices and edges, respectively. Each subsequent line describes an edge (the first two numbers are its tail and head, respectively) and its length (the third number). NOTE: some of the edge lengths are negative. NOTE: These graphs may or may not have negative-cost cycles.

Your task is to compute the "shortest shortest path". Precisely, you must first identify which, if any, of the three graphs have no negative cycles. For each such graph, you should compute all-pairs shortest paths and remember the smallest one (i.e., compute min_{u,v∈V} d(u,v), where d(u,v) denotes the shortest-path distance from u to v).
