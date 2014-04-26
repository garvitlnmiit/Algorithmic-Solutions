Strongly Connected Components
=============================

A Strongly Connected Component of a Directed Graph G=(V,E) is a maximal set of vertices C <= V such that for every pair
of vertices u and v in C, we have both u -> v and v -> u; that is, vertices u and v are reachable from each other.

Algorithm
----------

+ Call DFS(G) to compute finishing times u.f for each vertices u.
+ Compute Gt = Transpose(G).
+ Call DFS(Gt), but in the main loop of DFS, consider the vertices in order of decreasing u.f .
+ Output the vertices of each tree in the depth-first forest as a saperate strongly connected component.

Runing Time
-----------

+ The above algorithm is a linear time i,e theta(V+E).

Implementation
--------------

+ The language used for the implementation is C. 
