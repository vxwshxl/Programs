# 36. Write a Python program to perform graph partitioning and analyze neighborhood properties.

import networkx as nx
from networkx.algorithms.community import kernighan_lin_bisection

G = nx.karate_club_graph()

A, B = kernighan_lin_bisection(G, seed=42)
print("Partition A:", sorted(A))
print("Partition B:", sorted(B))
print("Edges cut:", nx.cut_size(G, A, B))

node = 0
print(f"\nNeighbors of node {node}:", sorted(G.neighbors(node)))
print(f"Degree of node {node}:", G.degree(node))
print(f"Clustering Coefficient of node {node}:", nx.clustering(G, node))

# Output:
# Partition A: [8, 14, 15, 18, 20, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33]
# Partition B: [0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 16, 17, 19, 21]
# Edges cut: 10
#
# Neighbors of node 0: [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 17, 19, 21, 31]
# Degree of node 0: 16
# Clustering Coefficient of node 0: 0.15
